/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 11:56:52 by djin              #+#    #+#             */
/*   Updated: 2023/08/25 14:56:26 by djin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

/*
O_TRUNC : This flag indicates that if the file already exists,
			its contents should be truncated (emptied)
O_CREAT : This flag indicates that if the file doesn't exist,
			it should be created

Fork() : Fork and created 2 process the child and parent process
Why fork():
			Data Sharing: Pipe that was created before fork
							is shared between the parent and child processes.
			Communication: the parent and child processes can both access 
							the pipe for communication.
			Seperate Process: run two separate processes in parallel, each 
							with its own execution context, memory space, and program counter.
Child Process: PID is 0
Parent Process: PID is more than 0
PID: Process IDentification
*/

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc != 5)
		perror("Wrong Arguments");
	if (pipe((int *)(pipex.fd)) == -1)
		error_exit("Pipe");
	pipex.pid = fork();
	if (pipex.pid == -1)
		error_exit(FORK_FAIL);
	if (pipex.pid == 0)
		child_process(pipex, argv[2], envp, argv[1]);
	parent_process(pipex, argv[3], envp, argv[4]);
}
