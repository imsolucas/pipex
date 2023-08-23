/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 13:41:00 by djin              #+#    #+#             */
/*   Updated: 2023/08/23 20:23:25 by djin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// push string to the front
char	*push_forward(char *buff)
{
	char	*str;
	int		n_len; // new length = tmp[new_len]
	int		p_len;
	
	p_len = 0; //previous length
	while (buff[p_len] != '\0' && buff[p_len] != '\n')
		p_len++;
	if (!buff[p_len])
	{
		free(buff);
		return (NULL);
	}
	str = ft_calloc(1, ft_strlen1(buff) - p_len);
	if (!str)
		return (NULL);
	p_len++;
	n_len = 0;
	while (buff[p_len] != '\0')
		str[n_len++] = buff[p_len++];
	free (buff);
	return (str);
}

//store the read line into a string
char	*store_line(char *buff)
{
	char	*str;
	int		sbuff_len;

	if (!buff[0])
		return (NULL);
	sbuff_len = 0;
	while (buff[sbuff_len] != '\n' && buff[sbuff_len] != '\0')
		sbuff_len++;
	str = ft_calloc(1, sbuff_len + 2);
	if (!str)
		return (NULL);
	sbuff_len = 0;
	while (buff[sbuff_len] != '\n' && buff[sbuff_len] != '\0')
	{
		str[sbuff_len] = buff[sbuff_len];
		sbuff_len++;
	}
	if (buff[sbuff_len] == '\n')
		str[sbuff_len] = '\n';
	return (str);
}

//read the text
static char	*read_txt(int fd, char *buff)
{
	char	*tmp;
	ssize_t	count;

	tmp = ft_calloc(1, BUFFER_SIZE + 1);
	if (!tmp)
		return (NULL);
	count = 1;
	while (count != 0 && !ft_strchr(buff, '\n'))
	{
		count = read(fd, tmp, BUFFER_SIZE);
		if (count == -1)
		{
			free (tmp);
			return (NULL);
		}
		tmp[count] = '\0';
		buff = ft_strjoin1(buff, tmp);
	}
	free (tmp);
	return (buff);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*store_nline;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = read_txt(fd, buff);
	if (!buff)
		return (NULL);
	store_nline = store_line(buff);
	buff = push_forward(buff);
	return (store_nline);
}
