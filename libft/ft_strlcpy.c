/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 17:03:59 by djin              #+#    #+#             */
/*   Updated: 2023/05/08 19:00:59 by djin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcpy(char *dest, const char *src, unsigned int size)
{
	unsigned int	i;

	if (!size)
		return (ft_strlen(src));
	i = 0;
	if (size > 0)
	{
		while (i < (size - 1) && src[i] != '\0')
		{
			dest[i] = src[i];
			i++;
		}
	}
	dest[i] = '\0';
	while (src[i])
		i++;
	return (i);
}

// int	main(void)
// {
// 	char	dst[] = "Hell0";
// 	char	src[5];
// 	unsigned int size = 10;

// 	printf("%d\n", ft_strlcpy(src, dst, size));
// 	printf("%s", src);
// }