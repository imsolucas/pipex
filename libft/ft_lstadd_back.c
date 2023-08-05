/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 23:39:16 by djin              #+#    #+#             */
/*   Updated: 2023/05/08 17:00:47 by djin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*newnode;

	if (!lst || !new)
		return ;
	newnode = *lst;
	if (lst)
	{
		if (newnode)
		{
			newnode = ft_lstlast(newnode);
			newnode -> next = new;
		}
		else
			*lst = new;
	}
}
