/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 11:56:52 by djin              #+#    #+#             */
/*   Updated: 2023/09/06 15:05:44 by djin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex_bonus.h"

/*
open_in_and_out : open file and set infile to RDONLY
					and outfile to WRONLY, O_TRUNC and O_CREAT
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

void	open_in_and_out(t_pipex *pipe, char **argv, int argc)
{
	pipe->outfile = open(argv[argc - 1], O_WRONLY | O_TRUNC | O_CREAT, 0666);
	if (pipe->outfile < 0)
		error_exit(argv[argc - 1]);
	pipe->infile = open(argv[1], O_RDONLY);
	if (pipe->infile < 0)
		error_exit(argv[1]);
	dup2(pipe->infile, STDIN_FILENO);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipes;
	int		fd[2];

	if (!(ft_strncmp(argv[1], "here_doc", 9)) && argc == 6)
	{
		here_doc(argv[2], &pipes, argv, argc);
		pipes.idx = 3;
	}
	else
	{
		open_in_and_out(&pipes, argv, argc);
		pipes.idx = 2;
	}
	processes(pipes, argv, envp, argc);
	dup2(pipes.outfile, STDOUT_FILENO);
	exec(argv[argc - 2], envp);
}
