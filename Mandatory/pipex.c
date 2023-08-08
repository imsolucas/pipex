/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 11:56:52 by djin              #+#    #+#             */
/*   Updated: 2023/08/08 15:03:28 by djin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc != 5)
		error_exit("Wrong arguments");
	if (pipe((int *)(pipex.fd)) == -1)
		error_exit("Pipe");
	pipex.pid = fork();
	if (pipex.pid == -1)
		error_exit(FORK_FAIL);
	if (pipex.pid == 0)
		child_process(pipex, argv[2], envp, argv[1]);
	parent_process(pipex, argv[3], envp, argv[4]);
}
