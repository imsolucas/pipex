/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 13:23:55 by djin              #+#    #+#             */
/*   Updated: 2023/08/11 19:12:16 by djin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex_bonus.h"

void	child_process(t_pipex pipe, char *argv, char **envp, char *infile)
{
	if (pipe.idx == 3)
		close(pipe.fd[0]);
	else
		close(pipe.fd[1]);
	dup2(pipe.fd[1], STDOUT_FILENO);
	execute(argv, envp);
}

void	parent_process(t_pipex pipe, char *argv, char **envp, char *outfile)
{
	int	status;

	waitpid(-1, &status, 0);
	close(pipe.fd[1]);
	dup2(pipe.fd[0], STDIN_FILENO);
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
	exit(1);
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
