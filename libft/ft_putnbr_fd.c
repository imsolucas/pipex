/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 20:20:17 by djin              #+#    #+#             */
/*   Updated: 2023/05/09 00:49:24 by djin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnumber(long n, char *buffer)
{
	int		i;
	long	temp;

	temp = n;
	i = 0;
	if (n == 0)
		buffer[i++] = '0';
	if (n < 0)
		n *= -1;
	while (n)
	{
		buffer[i] = n % 10 + '0';
		i++;
		n /= 10;
	}
	if (temp < 0)
		buffer[i++] = '-';
	buffer[i] = '\0';
}

static void	ft_reverse_print(char *str, char *buffer)
{
	int		length;
	long	i;

	length = ft_strlen(buffer);
	i = 0;
	while (length--)
		str[i++] = buffer[length];
	str[i] = '\0';
}

static void	ft_print_fd(int fd, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}	
}

void	ft_putnbr_fd(int n, int fd)
{
	char	buffer[46985];
	char	str[46985];

	ft_putnumber(n, buffer);
	ft_reverse_print(str, buffer);
	ft_print_fd(fd, str);
}

// int	main(void)
// {
// 	ft_putnbr_fd(0, 1);
// }
