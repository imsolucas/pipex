/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 17:23:57 by djin              #+#    #+#             */
/*   Updated: 2023/07/23 20:22:26 by djin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char	*str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	o;

	if (!len && !str)
		return (NULL);
	i = 0;
	if (!to_find[i])
		return ((char *)str + i);
	while (str[i] && (i < len))
	{
		o = 0;
		while (to_find[o])
		{
			if (str[i + o] == to_find[o] && ((i + o) < len))
			{
				o++;
				if (!to_find[o])
					return ((char *)str + i);
			}
			else
				break ;
		}
		i++;
	}
	return (NULL);
}

// int map_check(char *s)
// {
// 	int len = ft_strlen(s) - 1;

// 	if (s[len] == 'r' && s[len - 1] == 'e'
// 		&& s[len - 2] == 'b' && s[len - 3] == '.')
// 	{
// 		return (1);
// 	}
// 	return (0);
// }

// int main(int ac, char **av)
// {
// 	if (map_check(av[1]) == 1)
// 	{

// 	}
// 	else
// 	{

// 	}
// }
/*int	main(void)
{
	char	str[] = "th the nuts";
	char	tofind[] = "the";
	unsigned int	i = 6;

	char	*cmb = strnstr(str, tofind, i);

	printf ("%s", cmb);
}*/