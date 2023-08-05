/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 13:23:55 by djin              #+#    #+#             */
/*   Updated: 2023/08/05 16:00:04 by djin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

void	child_process(t_pipex pipe, char **argv, char **envp)
{
	pipe.infile = open(argv[1], O_RDONLY);
	close(pipe.fd[1]);
	dup2(pipe.fd[1], STDOUT_FILENO);
	dup2(pipe.infile, STDIN_FILENO);
	printf("This is the child process my pid is %d\n", pipe.pid);
	close(pipe.fd[0]);
	// close(dup2(pipe.fd[1], STDOUT_FILENO));
	// close(dup2(pipe.infile, STDIN_FILENO));
	execute(argv[2], envp);
}

void	parent_process(t_pipex pipe, char **argv, char **envp)
{
	int	status;

	waitpid(-1, &status, 0);
	pipe.outfile = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0777);
	close(pipe.fd[0]);
	dup2(pipe.fd[0], STDIN_FILENO);
	dup2(pipe.outfile, STDOUT_FILENO);
	close(pipe.fd[1]);
	printf("This is a parent process my child's pid is %d\n", pipe.pid);
	// close(dup2(pipe.fd[0], STDIN_FILENO));
	// close(dup2(pipe.outfile, STDOUT_FILENO));
	execute(argv[3], envp);
}

int	check_quotes(char quotes)
{
	if (quotes == '\"' || quotes == '\'')
		return (1);
	return (0);
}

int	len_quotes(char *str)
{
	int	i;

	if (!str || !(*str))
		return (0);
	i = 0;
	while (str[i] != '\"' && str[i] != '\'' && str[i])
		i++;
	return (i);
}

void	free_string(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

// cmd cat

// /usr/local/bin
// /usr/bin
// /bin
// /usr/sbin
// /sbin
// /usr/local/munki

// ./pipex file1 "cat -e -e -w" cmd2 file2
