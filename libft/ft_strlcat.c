/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 17:32:48 by djin              #+#    #+#             */
/*   Updated: 2023/05/09 18:37:18 by djin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	dest_length;
	size_t	temp;

	if (size == 0)
		return (ft_strlen(src));
	temp = ft_strlen(dest);
	dest_length = ft_strlen(dest);
	i = 0;
	while (dest_length < (size - 1) && size && src[i])
		dest[dest_length++] = src[i++];
	dest[dest_length] = '\0';
	if (size > temp)
		return (temp + ft_strlen(src));
	return (size + ft_strlen(src));
}

// int main(void)
// {
//     char dest[30] = "Hel";
//     char *src = "AAAAAA";
// 	printf("%zu\n", ft_strlcat(dest, src, -2));
// 	printf("%s\n", dest);
// }