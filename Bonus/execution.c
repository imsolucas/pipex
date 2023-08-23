/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 19:38:07 by djin              #+#    #+#             */
/*   Updated: 2023/08/23 22:04:59 by djin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex_bonus.h"

char	**split_string(t_pipex *pipe)
{
	int	len;
	int	word;
	int	i;

	i = 0;
	word = 0;
	len = 0;
	while (pipe->cmd[i])
	{
		if (checker(pipe->cmd[i]) == 1)
			i++;
		if (checker(pipe->cmd[i]) == 0)
		{
			pipe->result[word][len] = '\0';
			word++;
			len = 0;
			pipe->result[word] = (char *)malloc(sizeof(char) * (ft_strlen(pipe->cmd)));
		}
		else
			pipe->result[word][len++] = pipe->cmd[i];
		i++;
	}
	if (len > 0)
		pipe->result[word++][len] = '\0';
	pipe->result[word] = NULL;
	return (pipe->result);
}

char	*find_cmd_path(char *cmd, char **envp, t_pipex *pipe)
{
	size_t	i;

	i = 0;
	if (envp[i] != NULL)
	{
		while (ft_strncmp(envp[i], "PATH=", 5) != 0)
			i++;
		pipe->split_path = ft_split(envp[i] + 5, ':');
	}
	i = 0;
	while (pipe->split_path[i])
	{
		pipe->split_path[i] = ft_strjoin(pipe->split_path[i], "/");
		pipe->cmd_path = ft_strjoin(pipe->split_path[i], cmd);
		if (access(pipe->cmd_path, F_OK | X_OK) == 0)
			return (pipe->cmd_path);
		free(pipe->cmd_path);
		i++;
	}
	free_string(pipe->split_path);
	return (NULL);
}

void	execute(char *cmd, char **envp)
{
	t_pipex	*pipe;

	pipe->cmd = cmd;
	ft_putstr_fd(pipe->cmd, 1);
	pipe->result = (char **)malloc(sizeof(char *) * ((ft_strlen(pipe->cmd) - 2 + 1)));
	pipe->result[0] = (char *)malloc(sizeof(char) * (ft_strlen(pipe->cmd)));
	pipe->result[ft_strlen(pipe->cmd) + 1] = NULL;
	pipe->split_cmd = split_string(pipe);
	pipe->cmd_path = find_cmd_path(pipe->split_cmd[0], envp, pipe);
	if (!pipe->cmd_path)
		error_exit("wrong command");
	if (execve(pipe->cmd_path, pipe->split_cmd, envp) < 0)
		error_exit("Cannot execute");
}
