/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 21:50:54 by djin              #+#    #+#             */
/*   Updated: 2023/08/23 17:17:06 by djin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

#include "../Mandatory/get_next_line.h"
#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlen(char	const *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	int		i;
	int		len1;
	int		len2;

	if (!s1 && !s2)
		return (NULL);
	len1 = ft_strlen((char *) s1);
	len2 = ft_strlen((char *) s2);
	join = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!join)
		return (NULL);
	i = -1;
	while (++i < len1)
		join[i] = s1[i];
	i = -1;
	while (++i < len2)
		join[len1 + i] = s2[i];
	join[len1 + i] = '\0';
	free((void *)s1);
	return (join);
}

char	*ft_strchr(const char *str, int c)
{
	int	i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] == (char) c)
			return ((char *)str + i);
		i++;
	}
	if (c == 0)
		return ((char *)str + i);
	return (NULL);
}

// int	main(void)
// {
// 	char	str[] = "Hello World";
// 	char	*str2;

// 	str2 = ft_strdup(str);
// 	printf("%s\n", ft_strdup(str2));
// }

// int	main(void)
// {
// 	char	str[] = "www.youtube.com";

// 	printf("%s\n", ft_strchr(str, 'o'));
// }

// int	main(void)
// {
// 	printf("%s\n", ft_strjoin("Hello ", "There"));
// }
