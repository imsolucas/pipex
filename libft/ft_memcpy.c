/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 21:33:26 by djin              #+#    #+#             */
/*   Updated: 2023/05/09 18:14:55 by djin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t count)
{
	size_t			i;
	char			*char_dest;
	char			*char_src;

	char_dest = (char *)dest;
	char_src = (char *)src;
	if (!dest && !src)
		return (NULL);
	i = 0;
	while (i < count)
	{
		char_dest[i] = char_src[i];
		i++;
	}
	return (dest);
}

// int	main(void)
// {
// 	char	source[] = "Hello World";
// 	char	destination[] = "Hello World";

// 	printf("%s", memcpy(destination+2, source, sizeof(source)-2));
// }
