/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 13:23:55 by djin              #+#    #+#             */
/*   Updated: 2023/08/12 13:50:18 by djin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

/*
Child Process: calls the process to write or read
dup2: Use to duplicate file descripter.
open: open infile as read only
close: Close my read pipe to prevent resource leaks
	Closing the read end of the pipe in the child process 
	signals to the parent process that no more data will be 
	read from that pipe
*/
void	child_process(t_pipex pipe, char *argv, char **envp, char *infile)
{
	pipe.infile = open(infile, O_RDONLY);
	close(pipe.fd[0]);
	dup2(pipe.fd[1], STDOUT_FILENO);
	dup2(pipe.infile, STDIN_FILENO);
	execute(argv, envp);
}

/*
Parent Process: Process is passed in by child process to execute onwards
				at the end of the process
waitpid: Allows you to pause the parent process and wait for the child to
			run finish the process
open: open my outfile as read and write
close: Close my write end pipe to
		ensures that the parent process won't accidentally
		continue writing data to the pipe.
*/
void	parent_process(t_pipex pipe, char *argv, char **envp, char *outfile)
{
	int	status;

	waitpid(-1, &status, 0);
	pipe.outfile = open(outfile, O_CREAT | O_RDWR | O_TRUNC, 0777);
	close(pipe.fd[1]);
	dup2(pipe.fd[0], STDIN_FILENO);
	dup2(pipe.outfile, STDOUT_FILENO);
	execute(argv, envp);
}

/*
checks for quotes or spaces
if It's space or tabs, return 0
else if it's '\'' or '\"', return 1
*/
int	checker(char c)
{
	if (c == ' ' || c == '\t')
		return (0);
	if (c == '\'' || c == '\"')
		return (1);
	return (2);
}

//deletes string
void	free_string(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	error_exit(char *str)
{
	perror(str);
	exit(1);
}
