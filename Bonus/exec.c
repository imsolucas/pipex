/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 08:11:27 by djin              #+#    #+#             */
/*   Updated: 2023/08/24 08:54:37 by djin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex_bonus.h"

char	*get_path(char *cmd, char **envp)
{
	char	**path;
	char	*tmp;
	char	*tmp2;
	int		i;

	i = 0;
	while (ft_strncmp(envp[i], "PATH=", 5))
		i++;
	path = ft_split(envp[i] + 5, ':');
	i = 0;
	while (path[i])
	{
		tmp = ft_strjoin(path[i], "/");
		tmp2 = ft_strjoin(tmp, cmd);
		free(tmp);
		if (!access(tmp2, F_OK))
		{
			free_split(path);
			return (tmp2);
		}
		free(tmp2);
		i++;
	}
	free_split(path);
	return (cmd);
}

void	exec(char *cmd, char **envp)
{
	t_pipex pipe;

	// pipe = create_token(cmd);
	pipe.split_cmd = ft_split(cmd, ' ');
	pipe.cmd = pipe.split_cmd[0];
	pipe.cmd_path = get_path(pipe.cmd, envp);
	if (!pipe.cmd_path)
		error_exit("Error: command not found");
	if (execve(pipe.cmd_path, pipe.split_cmd, envp) == -1)
		error_exit("Error: command not found");
}
