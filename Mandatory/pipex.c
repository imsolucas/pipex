/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 11:56:52 by djin              #+#    #+#             */
/*   Updated: 2023/08/05 15:26:09 by djin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	// printf("%s\n", find_cmd_path(argv[2], envp, &pipex));
	if (argc != 5)
		error_exit("Wrong arguments");
	if (pipe((int *)(pipex.fd)) == -1)
		error_exit("Pipe");
	pipex.pid = fork();
	if (pipex.pid == -1)
		error_exit(FORK_FAIL);
	if (pipex.pid == 0)
		child_process(pipex, argv, envp);
	parent_process(pipex, argv, envp);
}
