/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:23:20 by djin              #+#    #+#             */
/*   Updated: 2023/09/06 14:55:42 by djin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex_bonus.h"

static void	open_here_doc(t_pipex *pipes, char **argv, int argc)
{
	pipes->outfile = open(argv[argc - 1], O_WRONLY | O_CREAT, 0666);
	if (pipes->outfile < 0)
		error_exit(argv[argc - 1]);
}

void	child_heredoc(char *limiter, int *fd)
{
	char	*line;

	close(fd[0]);
	write (2, "pipe heredoc> ", 14);
	line = get_next_line(0);
	while (line)
	{
		if (!ft_strncmp(line, limiter, ft_strlen(line) - 1))
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		write(fd[1], line, ft_strlen(line));
		free(line);
		write (2, "pipe heredoc> ", 14);
		line = get_next_line(0);
	}
}

void	here_doc(char *limiter, t_pipex *pipes, char **argv, int argc)
{
	char	*line;
	int		fd[2];

	open_here_doc(pipes, argv, argc);
	if (pipe(fd) == -1)
		error_exit("Pipe ");
	pipes->pid = fork();
	if (pipes->pid == -1)
		error_exit(FORK_FAIL);
	if (pipes->pid == 0)
		child_heredoc(limiter, fd);
	else
	{
		waitpid(-1, NULL, 0);
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
	}
}
