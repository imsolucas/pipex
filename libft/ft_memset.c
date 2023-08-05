/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 20:18:31 by djin              #+#    #+#             */
/*   Updated: 2023/04/28 22:41:35 by djin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int ch, size_t count)
{
	unsigned int	i;
	char			*char_dest;

	i = 0;
	char_dest = (char *)dest;
	while (i < count)
	{
		char_dest[i] = ch;
		i++;
	}
	return (dest);
}

/*int	main(void)
{
	char dest[50];
	char ch = 'a';

	printf("%s", ft_memset(dest, ch, 20));
}*/