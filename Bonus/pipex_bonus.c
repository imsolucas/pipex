/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 11:56:52 by djin              #+#    #+#             */
/*   Updated: 2023/08/09 19:30:41 by djin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;
	int		len;
	int		i;

	i = 0;
	len = 0;
	if (argc < 5)
		error_exit("Wrong arguments");
	if (pipe((int *)(pipex.fd)) == -1)
		error_exit("Pipe");
	while (argv[i] && i > 1 && i <= len)
	{
		if (i == argc - 2)
			dup2(pipex.outfile, STDOUT_FILENO);
		pipex.pid = fork();
		if (pipex.pid == -1)
			error_exit(FORK_FAIL);
		if (pipex.pid == 0)
			child_process(pipex, argv[i], envp);
		parent_process(pipex, argv[i], envp);
		dup2(pipex.fd[0], STDIN_FILENO);
		i++;
	}
	// pipex.pid = fork();
	// if (pipex.pid == -1)
	// 	error_exit(FORK_FAIL);
	// if (pipex.pid == 0)
	// 	child_process(pipex, argv[2], envp, argv[1]);
	// parent_process(pipex, argv[3], envp, argv[4]);
}
