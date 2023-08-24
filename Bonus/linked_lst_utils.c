/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_lst_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 08:18:18 by djin              #+#    #+#             */
/*   Updated: 2023/08/24 08:44:18 by djin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex_bonus.h"

t_pipex	*create_token(char *cmd)
{
	t_pipex	*token;

	token = (t_pipex *)malloc(sizeof(t_pipex));
	if (!token)
		return (NULL);
	token->cmd = cmd;
	token->next = NULL;
	token->prev = NULL;
	return (token);
}

void	add_token(t_pipex **head, t_pipex *new_token)
{
	t_pipex	*tmp;

	if (!*head)
		*head = new_token;
	else
	{
		tmp = *head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_token;
		new_token->prev = tmp;
	}
}

void	free_token(t_pipex **head)
{
	t_pipex	*tmp;

	while (*head)
	{
		tmp = *head;
		*head = (*head)->next;
		free(tmp->cmd);
		free(tmp);
	}
}
