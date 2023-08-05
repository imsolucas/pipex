/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 22:42:01 by djin              #+#    #+#             */
/*   Updated: 2023/05/09 18:25:08 by djin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t count)
{
	unsigned char	*char_dest;
	unsigned char	*char_src;
	size_t			i;

	char_dest = (unsigned char *)dest;
	char_src = (unsigned char *)src;
	i = 0;
	if ((!char_dest && !char_src))
		return (NULL);
	if (char_dest > char_src)
	{
		while (count--)
			char_dest[count] = char_src[count];
	}
	else
	{
		while (i < count)
		{
			char_dest[i] = char_src[i];
			i++;
		}
	}
	return (dest);
}

// int	main(void)
// {
// 	char	dest[50] = "World";
// 	char	src[50] = "Hello World";
// 	ft_memmove(dest, src, 5);
// 	printf("%s", dest);
// }
