/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 15:45:43 by djin              #+#    #+#             */
/*   Updated: 2023/05/09 18:30:03 by djin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void *ptr, int ch, size_t count)
{
	unsigned int	i;
	char			*char_ptr;
	char			char_c;

	char_ptr = ((char *)ptr);
	char_c = (char)ch;
	i = 0;
	while (i < count)
	{
		if (char_ptr[i] == char_c)
			return ((void *)ptr + i);
		i++;
	}
	return (NULL);
}

/*int	main(void)
{
	char	ptr[] = "My Name is Lucas";
	int	ch = '\0';
	printf("%s\n", ft_memchr(ptr, ch, 0));
}*/