/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 11:16:44 by djin              #+#    #+#             */
/*   Updated: 2023/05/09 18:46:26 by djin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	t_list	*prevnode;

	if (!lst || !del)
		return ;
	prevnode = lst;
	if (!prevnode)
		return ;
	else if (prevnode)
	{
		del(prevnode -> content);
		free (prevnode);
	}
}
