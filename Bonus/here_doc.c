/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:23:20 by djin              #+#    #+#             */
/*   Updated: 2023/09/05 21:35:43 by djin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex_bonus.h"

static void	open_here_doc(t_pipex *pipes, char **argv, int argc)
{
	pipes->outfile = open(argv[argc - 1], O_WRONLY | O_CREAT, 0666);
	if (pipes->outfile < 0)
		error_exit(argv[argc - 1]);
}

void	here_doc(char *limiter, t_pipex *pipes, char **argv, int argc)
{
	char	*line;
	int		fd[2];

	open_here_doc(pipes, argv, argc);
	if (pipes->pid == 0)
	{
		close(fd[0]);
		while (1)
		{
			write (1, "pipe heredoc> ", 14);
			line = get_next_line(0);
			if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
			{
				free(line);
				break ;
			}
			write(fd[1], line, ft_strlen(line));
			// write(pipes->fd_out, "\n", 1);
			free(line);
		}
	}
	else
	{
		waitpid(pipes->pid, NULL, 0);
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		printf("%d\n", fd[0]);
	}
}
