/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 20:41:30 by djin              #+#    #+#             */
/*   Updated: 2023/05/09 18:02:39 by djin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

/*int	main(void)
{
	char str[] = {0,1,2,3,4,5,6};
	unsigned	int i;
	
	ft_bzero(str, 7);
	i = 0;
	while(i < 7)
	{
	printf("%d", str[i]);
	i++;
	}
}*/
