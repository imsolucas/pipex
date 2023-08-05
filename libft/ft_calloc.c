/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 19:58:29 by djin              #+#    #+#             */
/*   Updated: 2023/05/09 18:40:22 by djin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void		*ptr;
	size_t		i;

	i = 0;
	if (num == SIZE_MAX || size == SIZE_MAX)
		return (NULL);
	ptr = (char *)malloc (num * size);
	if (!ptr)
		return (NULL);
	while (i < (size * num))
	{
		*((char *)ptr + i) = 0;
		i++;
	}
	return (ptr);
}
