/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 12:53:00 by djin              #+#    #+#             */
/*   Updated: 2023/05/08 15:13:14 by djin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;
	int	j;
	int	mark;

	i = 0;
	j = 0;
	mark = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
		{
			j = i;
			mark = 1;
		}
		i++;
	}
	if (mark)
		return ((char *)str + j);
	else if (c == '\0')
		return ((char *)str + i);
	else
		return (NULL);
}

/*int	main(void)
{
	char str[] = "www.gmail.com";
	printf("%s", ft_strrchr(str, '-'));
}*/