/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 13:23:55 by djin              #+#    #+#             */
/*   Updated: 2023/09/06 16:45:18 by djin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex_bonus.h"

void	open_child(t_pipex *pipe, char **argv, char **envp)
{
	pipe->infile = open(argv[pipe->idx], O_RDONLY);
	if (pipe->infile < 0 && pipe->idx == 2)
		error_exit(argv[pipe->idx]);
}

void	processes(t_pipex pipes, char **argv, char **envp, int argc)
{
	int	fd[2];

	while (pipes.idx < (argc - 2))
	{
		if (pipe((fd)) == -1)
			error_exit("Pipe ");
		pipes.pid = fork();
		if (pipes.pid == -1)
			error_exit(FORK_FAIL);
		if (pipes.pid == 0)
		{
			open_child(&pipes, argv, envp);
			close(fd[0]);
			dup2(fd[1], STDOUT_FILENO);
			dup2(pipes.infile, STDIN_FILENO);
			exec(argv[pipes.idx], envp);
		}
		else
		{
			waitpid(pipes.pid, NULL, 0);
			close(fd[1]);
			dup2(fd[0], STDIN_FILENO);
		}
		pipes.idx++;
	}
}

void	error_exit(char *str)
{
	perror(str);
	exit(1);
}

//free string
void	free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}
