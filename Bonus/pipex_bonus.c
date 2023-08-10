/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 11:56:52 by djin              #+#    #+#             */
/*   Updated: 2023/08/10 17:50:58 by djin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex_bonus.h"

void	open_fd(t_pipex *pipe, char **argv, int argc)
{
	pipe->outfile = open(argv[argc - 1], O_WRONLY | O_TRUNC | O_CREAT, 0664);
	if (pipe->outfile < 0)
		error_exit(argv[argc - 1]);
	pipe->infile = open(argv[1], O_RDONLY);
	if (pipe->infile < 0)
		error_exit(argv[1]);
	dup2(pipe->infile, STDIN_FILENO);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;
	int		len;
	int		i;

	i = 0;
	len = 0;
	if (argc < 5)
		error_exit("Wrong arguments");
	open_fd(&pipex, argv, argc);
	i = 2;
	while (i < (argc - 2))
	{
		if (pipe((pipex.fd)) == -1)
			error_exit("Pipe ");
		pipex.pid = fork();
		if (pipex.pid == -1)
			error_exit(FORK_FAIL);
		if (pipex.pid == 0)
			child_process(pipex, argv[i], envp, argv[1]);
		else
			parent_process(pipex, argv[i], envp, argv[argc -1]);
		i++;
	}
	dup2(pipex.outfile, STDOUT_FILENO);
	execute(argv[argc - 2], envp);
}
