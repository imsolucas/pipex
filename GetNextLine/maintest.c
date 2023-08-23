/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 20:39:11 by djin              #+#    #+#             */
/*   Updated: 2023/07/11 10:02:11 by djin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	char	*buff;
	int		fd;
	int		fd2;

	fd = open("file1.txt", O_RDWR);
	fd2 = open("file1.txt", O_RDWR);
	buff = get_next_line(fd);
	printf("%s", buff);
	buff = get_next_line(fd);
	printf("%s", buff);
	buff = get_next_line(fd);
	printf("%s", buff);
	buff = get_next_line(fd);
	printf("%s", buff);
	buff = get_next_line(fd);
	printf("%s", buff);
}
