/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 13:23:55 by djin              #+#    #+#             */
/*   Updated: 2023/08/10 09:23:11 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

void	child_process(t_pipex pipe, char *argv, char **envp, char *infile)
{
	pipe.infile = open(infile, O_RDONLY);
	dup2(pipe.fd[1], STDOUT_FILENO);
	dup2(pipe.infile, STDIN_FILENO);
	close(pipe.fd[0]);
	execute(argv, envp);
}

void	parent_process(t_pipex pipe, char *argv, char **envp, char *outfile)
{
	int	status;

	waitpid(-1, &status, 0);
	pipe.outfile = open(outfile, O_CREAT | O_RDWR | O_TRUNC, 0777);
	dup2(pipe.fd[0], STDIN_FILENO);
	dup2(pipe.outfile, STDOUT_FILENO);
	close(pipe.fd[1]);
	execute(argv, envp);
}

int	checker(char c)
{
	if (c == ' ' || c == '\t')
		return (0);
	if (c == '\'' || c == '\"')
		return (1);
	return (2);
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
