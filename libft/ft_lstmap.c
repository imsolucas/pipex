/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 11:32:12 by djin              #+#    #+#             */
/*   Updated: 2023/05/08 22:11:06 by djin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_if(t_list **temp, t_list *newnode, t_list **head)
{
	if (*head == 0)
	{
		*head = newnode;
		*temp = newnode;
	}
	else
	{
		(*temp)-> next = newnode;
		*temp = newnode;
	}
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp;
	t_list	*newnode;
	t_list	*head;

	if (!lst || !f || !del)
		return (NULL);
	temp = 0;
	head = 0;
	while (lst != 0)
	{
		newnode = malloc(sizeof(t_list));
		if (!newnode)
			return (NULL);
		newnode -> content = (*f)(lst -> content);
		newnode -> next = 0;
		ft_if(&temp, newnode, &head);
		lst = lst -> next;
	}
	return (head);
}
