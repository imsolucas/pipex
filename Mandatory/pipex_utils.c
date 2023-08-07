/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 13:23:55 by djin              #+#    #+#             */
/*   Updated: 2023/08/07 17:32:19 by djin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

void	child_process(t_pipex pipe, char *argv, char **envp, char *infile)
{
	pipe.infile = open(infile, O_RDONLY);
	// close(pipe.fd[0]);
	dup2(pipe.fd[1], STDOUT_FILENO);
	dup2(pipe.infile, STDIN_FILENO);
	close(pipe.fd[0]);
	execute(argv, envp);
	// printf("This is the child process my pid is %d\n", pipe.pid);
	// close(dup2(pipe.fd[1], STDOUT_FILENO));
	// close(dup2(pipe.infile, STDIN_FILENO));

}

void	parent_process(t_pipex pipe, char *argv, char **envp, char *outfile)
{
	int	status;

	waitpid(-1, &status, 0);
	pipe.outfile = open(outfile, O_CREAT | O_RDWR | O_TRUNC, 0777);
	// close(pipe.fd[1]);
	dup2(pipe.fd[0], STDIN_FILENO);
	dup2(pipe.outfile, STDOUT_FILENO);
	close(pipe.fd[1]);
	// ft_putstr_fd(argv, 2);
	// printf("This is a parent process my child's pid is %d\n", pipe.pid);
	// close(dup2(pipe.fd[0], STDIN_FILENO));
	// close(dup2(pipe.outfile, STDOUT_FILENO));
	execute(argv, envp);
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
