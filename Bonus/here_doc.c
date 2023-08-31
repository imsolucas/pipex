/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:23:20 by djin              #+#    #+#             */
/*   Updated: 2023/08/31 08:10:45 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex_bonus.h"

static void	open_here_doc(t_pipex *pipe, char **argv, int argc)
{
	pipe->fd_out = open(argv[argc - 1], O_WRONLY | O_APPEND | O_CREAT, 0666);
	if (pipe->outfile < 0)
		error_exit(argv[argc - 1]);
	// dup2(pipe->fd[0], STDIN_FILENO);
}

void	here_doc(char *limiter, t_pipex *pipes, char **argv, int argc)
{
	char	*line;

	open_here_doc(pipes, argv, argc);
	// if (pipe(pipes->fd) < 0)
	// 	error_exit("pipe");
	pipes->pid = fork();
	if (pipes->pid == 0)
	{
		close(pipes->fd[0]);
		write (1, "heredoc> ", 9);
		line = get_next_line(STDIN_FILENO);
		limiter = ft_strjoin(limiter, "\n");
		while ((ft_strncmp(line, limiter, ft_strlen(limiter))))
		{
			write(pipes->fd[1], line, ft_strlen(line));
			free(line);
			write (1, "heredoc> ", 9);
			line = get_next_line(STDIN_FILENO);
		}
		free(line);
		close(pipes->fd[1]);
		printf("limiter reached\n");
		exit(0);
	}
	else
	{
		waitpid(pipes->pid, NULL, 0);
		// read(pipes->fd[0], buff, 1000);
		// printf("buff: %s\n", buff);
		close(pipes->fd[1]);
		dup2(pipes->fd[0], STDIN_FILENO);
		close(pipes->fd[0]);
	}
}
