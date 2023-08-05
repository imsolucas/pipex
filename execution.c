/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 19:38:07 by djin              #+#    #+#             */
/*   Updated: 2023/08/05 15:28:19 by djin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

char	**split_string(t_pipex pipe, int word, int i_copy, int i)
{
	while (pipe.cmd[i] != 0)
	{		
		if (check_quotes(pipe.cmd[i]) == 1)
			i++;
		if ((check_quotes(pipe.cmd[i]) == 0) && pipe.result[word])
		{
			pipe.result[word] = malloc(sizeof(char) * (ft_strlen(pipe.cmd) + 1));
			i = len_quotes(pipe.cmd);
			pipe.result[word] = ft_substr(pipe.cmd, 0, i);
			word++;
		}
		i++;
	}
	pipe.result[word] = NULL;
	return (pipe.result);
}

char	*find_cmd_path(char *cmd, char **envp, t_pipex *pipe)
{
	size_t	i;

	if (access(cmd, F_OK) == 0)
		return (cmd);
	i = 0;
	if (envp[i])
	{
		while (ft_strncmp(envp[i], "PATH=", 5) != 0)
			i++;
		pipe->split_path = ft_split(envp[i] + 5, ':');
	}
	i = 0;
	while (pipe->split_path[i] != NULL)
	{
		pipe->split_path[i] = ft_strjoin(pipe->split_path[i], "/");
		pipe->cmd_path = ft_strjoin(pipe->split_path[i], cmd);
		if (access(pipe->cmd_path, F_OK) == 0)
			return (pipe->cmd_path);
		free(pipe->cmd_path);
		i++;
	}
	free_string(pipe->split_path);
	return (NULL);
}

void	execute(char *cmd, char **envp)
{
	t_pipex	pipe;

	pipe.cmd = cmd;
	pipe.result = (char **)malloc(sizeof(char *) * (ft_strlen(pipe.cmd) + 1));
	pipe.result[ft_strlen(pipe.cmd)] = 0;
	pipe.split_cmd = split_string(pipe, 0, 0, 0);
	// printf("check:%s\n", *pipe.split_cmd);
	// fflush(0);
	pipe.cmd_path = find_cmd_path(pipe.split_cmd[0], envp, &pipe);
	// dprintf(2, "check:%s\n", pipe.split_cmd[1]);
	// fflush(0);
	if (!pipe.cmd_path)
		error_exit("wrong command");
	// if (execve(pipe.cmd_path, pipe.split_cmd, envp) < 0)
	// 	error_exit("Cannot execute");
	// execve(pipe.cmd_path, pipe.split_cmd, envp);
	execve(pipe.cmd_path, pipe.split_cmd, envp);
}
