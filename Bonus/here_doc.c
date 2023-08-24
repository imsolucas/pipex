/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:23:20 by djin              #+#    #+#             */
/*   Updated: 2023/08/24 10:52:33 by djin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex_bonus.h"

static void	open_here_doc(t_pipex *pipe, char **argv, int argc)
{
	pipe->outfile = open(argv[argc - 1], O_WRONLY | O_TRUNC | O_CREAT, 0666);
	if (pipe->outfile < 0)
		error_exit(argv[argc - 1]);
	dup2(pipe->fd[0], STDIN_FILENO);
}

void	here_doc(char *limiter, t_pipex *pipes, char **argv, int argc)
{
	char	*line;

	open_here_doc(pipes, argv, argc);
	pipes->pid = fork();
	if (pipes->pid == 0)
	{
		while (1)
		{
			write (1, "heredoc> ", 9);
			line = get_next_line(0);
			if (!(ft_strncmp(line, limiter, ft_strlen(limiter))))
				break ;
			write(pipes->fd[0], line, ft_strlen(line));
			free(line);
		}
		free(line);
	}
	else
	{
		close(pipes->fd[1]);
		waitpid(-1, NULL, 0);
	}
}
