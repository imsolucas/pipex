/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:23:20 by djin              #+#    #+#             */
/*   Updated: 2023/08/23 18:42:43 by djin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex_bonus.h"

void	open_here_doc(t_pipex *pipe, char **argv, int argc)
{
	pipe->outfile = open(argv[argc - 1], O_WRONLY | O_TRUNC | O_CREAT, 0666);
	if (pipe->outfile < 0)
		error_exit(argv[argc - 1]);
	dup2(pipe->infile, STDIN_FILENO);
	pipe->idx = 3;
}

void	here_doc(char *limiter, t_pipex *pipes, char **argv, int argc)
{
	char	*line;

	open_here_doc(pipes, argv, argc);
	pipes->infile = open(".here_doc", O_WRONLY | O_TRUNC | O_CREAT, 0666);
	while (1)
	{
		write (1, "heredoc> ", 9);
		line = get_next_line(pipes->infile);
		if (!(ft_strncmp(line, limiter, ft_strlen(limiter))))
		{
			free(line);
			break ;
		}
		write(pipes->infile, line, ft_strlen(line));
		write(pipes->infile, "\n", 1);
		free(line);
	}
	close(pipes->infile);
	pipes->infile = open(".here_doc", O_RDONLY);
	dup2(pipes->infile, STDIN_FILENO);
	if (pipes->infile < 0)
	{
		unlink("here_doc");
		perror("here_doc");
		exit(1);
	}
}
