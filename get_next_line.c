/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 22:07:56 by mkoyamba          #+#    #+#             */
/*   Updated: 2022/02/08 21:19:49 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *str)
{
	char	*buff;
	int		rd;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	rd = 1;
	while (!ft_strchr(str, '\n') && rd != 0)
	{
		rd = read(fd, buff, BUFFER_SIZE);
		if (rd == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd] = '\0';
		str = ft_strjoin(str, buff);
	}
	free(buff);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= OPEN_MAX)
		return (NULL);
	str[fd] = ft_read(fd, str[fd]);
	if (!str[fd])
		return (NULL);
	line = ft_get_line(str[fd]);
	str[fd] = ft_update(str[fd]);
	return (line);
}
