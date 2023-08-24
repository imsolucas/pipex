/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 12:34:44 by djin              #+#    #+#             */
/*   Updated: 2023/08/24 08:50:15 by djin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	length;

	if (!set || !s1)
		return (NULL);
	length = ft_strlen(s1);
	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (s1[length - 1] && ft_strchr(set, s1[length - 1]))
		length--;
	return (ft_substr(s1 + i, 0, length - i));
}

int	main(void)
{
	char	str[] = "Hello World";

	printf("%s\n", ft_strtrim(str, ""));
}