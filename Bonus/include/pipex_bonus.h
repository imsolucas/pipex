/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 11:40:34 by djin              #+#    #+#             */
/*   Updated: 2023/10/29 20:05:37 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# define ENV_PATH "/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:"
# define FORK_FAIL "Fail to fork"

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <stdbool.h>
# include <sys/types.h>
# include "../../libft/libft.h"
# include "../../GetNextLine/get_next_line.h"

typedef struct s_pipex
{
	int		fd[2];
	int		idx;
	int		outfile;
	int		infile;
	char	*cmd;
	char	**split_cmd;
	char	*cmd_path;
	pid_t	pid;
}			t_pipex;

//init
void		pipe_exec(t_pipex pipex, char **argv, int argc, char **envp);

//processes
//out = outfile
void		parent_process(t_pipex pipe, char *argv, char **envp);
void		child_process(t_pipex pipe, char *argv, char **envp);
void		processes(t_pipex pipes, char **argv, char **envp, int argc);
void		child_heredoc(char *limiter, int *fd);

//execution
char		*find_cmd_path(char *cmd, char **envp, t_pipex *pipe);
void		exec(char *cmd, char **envp);

//utils
int			checker(char c);
void		free_split(char **str);
void		error_exit(char *str);
void		open_in_and_out(t_pipex *pipe, char **argv, int argc);

//here_doc
static void	open_here_doc(t_pipex *pipe, char **argv, int argc);
void		here_doc(char *limiter, t_pipex *pipes, char **argv, int argc);

int			ft_strcmp(const char *s1, const char *s2);

#endif