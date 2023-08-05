/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 10:19:49 by djin              #+#    #+#             */
/*   Updated: 2023/07/17 13:43:11 by djin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_seperator(char a, char check)
{
	if (a == check)
		return (1);
	return (0);
}

static int	count_string(char *str, char c)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && check_seperator(*str, c))
			str++;
		if (*str)
			count++;
		while (*str && !check_seperator(*str, c))
			str++;
	}
	return (count);
}

static int	ft_len(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && !check_seperator(str[i], c))
		i++;
	return (i);
}

static char	*print_word(char *str, char c)
{
	int		len;
	int		i;
	char	*word;

	len = ft_len(str, c);
	i = 0;
	word = (char *)malloc((len + 1) * sizeof(char));
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	*str;
	char	**arr;

	if (!s)
		return (NULL);
	i = 0;
	str = (char *)s;
	arr = (char **)malloc((count_string(str, c) + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	while (*str)
	{
		while (*str && check_seperator(*str, c))
			str++;
		if (*str)
		{
			arr[i] = print_word(str, c);
			i++;
		}
		while (*str && !check_seperator(*str, c))
			str++;
	}
	arr[i] = 0;
	return (arr);
}

//# include <stdio.h>

// int	main(void)
//  {
//  	char	**result = ft_split("Hello a voy", ' ');
//  	int		i;

//  	i = 0;
//  	while (result[i])
//  	{
//  		printf("%s", result[i]);
//  		i++;
//  	}
//  }

// int	main(void)
// {
// 	char	**result = ft_split("11111\n10001\n11111", '\n');
// 	int	i = 0;
// 	while(result[i])
// 	{
// 		printf("%s", result[i]);
// 		i++;
// 	}
// }
