/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 13:23:55 by djin              #+#    #+#             */
/*   Updated: 2023/08/10 09:22:51 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex_bonus.h"

void	child_process(t_pipex pipe, char *argv, char **envp, char *infile)
{
	// pipe.infile = open(infile, O_RDONLY);
	dup2(pipe.fd[1], STDOUT_FILENO);
	close(pipe.fd[0]);
	execute(argv, envp);
}

void	parent_process(t_pipex pipe, char *argv, char **envp, char *outfile)
{
	int	status;

	waitpid(-1, &status, 0);
	// pipe.outfile = open(outfile, O_CREAT | O_RDWR | O_TRUNC, 0777);
	dup2(pipe.fd[0], STDIN_FILENO);
	close(pipe.fd[1]);
}

int	checker(char c)
{
	if (c == ' ' || c == '\t')
		return (0);
	if (c == '\'' || c == '\"')
		return (1);
	return (2);
}

void	error_exit(char *str)
{
	perror(str);
	exit(0);
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
