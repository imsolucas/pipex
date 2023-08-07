/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 19:38:07 by djin              #+#    #+#             */
/*   Updated: 2023/08/07 17:53:13 by djin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

char	**split_string(t_pipex pipe)
{
	int	len;

	len = ft_strlen(pipe.cmd);
	pipe.result = ft_split(pipe.cmd, ' ');
	// ft_putstr_fd(pipe.result[0], 2);
	pipe.result[len + 1] = NULL;
	return (pipe.result);
}

// char	**split_string(t_pipex pipe)
// {
// 	int	i;
// 	int	word;
// 	int	idx;

// 	i = 0;
// 	word = 0;
// 	idx = 0;
// 	while (pipe.cmd[i] != '\0')
// 	{
// 		if (check_quotes(pipe.cmd[i]) == 1)
// 			i++;
// 		if (check_quotes(pipe.cmd[i]) == 0)
// 		{
// 			if (idx > 0)
// 			{
// 				pipe.result[word][idx] = '\0';
// 				word++;
// 				pipe.result[word] = malloc(ft_strlen(pipe.cmd) * sizeof(char));
// 				idx = 0;
// 			}
// 		}
// 		else
// 			pipe.result[word][idx++] = pipe.cmd[i];
// 		i++;
// 	}
// 	if (idx > 0)
// 		pipe.result[word++][idx] = '\0';
// 	pipe.result[word] = NULL;
// 	return (pipe.result);
// }

char	*find_cmd_path(char *cmd, char **envp, t_pipex *pipe)
{
	size_t	i;

	// if (access(cmd, F_OK | X_OK) == 0)
	// 	return (cmd);
	// ft_putstr_fd("im here\n", 2);
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
		// ft_putstr_fd(pipe->cmd_path, 2);
		// ft_putchar_fd('\n', 2);
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
	t_pipex	pipe;

	pipe.cmd = cmd;
	pipe.result = (char **)malloc(sizeof(char *) * (ft_strlen(pipe.cmd) + 1));
	pipe.result[ft_strlen(pipe.cmd)] = 0;
	pipe.split_cmd = split_string(pipe);
	// ft_putstr_fd(*pipe.split_cmd, 2);
	// printf("check:%s\n", *pipe.split_cmd);
	// fflush(0);
	pipe.cmd_path = find_cmd_path(pipe.split_cmd[0], envp, &pipe);
	// printf("%s\n\n", pipe.cmd_path);
	// ft_putstr_fd(pipe.cmd_path, 2);
	// ft_putchar_fd('\n', 2);
	// ft_putstr_fd(pipe.split_cmd[0], 2);
	// ft_putchar_fd('\n', 2);
	// ft_putstr_fd(pipe.split_cmd[1], 2);
	// ft_putchar_fd('\n', 2);
	// dprintf(2, "check:%s\n", pipe.split_cmd[1]);
	// fflush(0);
	if (!pipe.cmd_path)
		error_exit("wrong command");
	// if (execve(pipe.cmd_path, pipe.split_cmd, envp) < 0)
	// 	error_exit("Cannot execute");
	execve(pipe.cmd_path, pipe.split_cmd, envp);
	// execve(pipe.cmd_path, pipe.split_cmd, envp);
}
