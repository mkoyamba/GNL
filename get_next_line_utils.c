/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 09:32:57 by mkoyamba          #+#    #+#             */
/*   Updated: 2022/02/08 21:02:43 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	x;

	x = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[x] != '\0')
	{
		if (s[x] == (char) c)
			return ((char *)&s[x]);
		x++;
	}
	return (0);
}

char	*ft_strjoin(char *str, char *buff)
{
	size_t	a;
	size_t	b;
	char	*line;

	if (!str)
	{
		str = (char *)malloc(sizeof(char) * 1);
		if (!str || !buff)
			return (NULL);
		str[0] = '\0';
	}
	line = malloc(sizeof(char) * ((ft_strlen(str) + ft_strlen(buff)) + 1));
	if (line == NULL)
		return (NULL);
	a = -1;
	b = 0;
	if (str)
		while (str[++a] != '\0')
			line[a] = str[a];
	while (buff[b] != '\0')
		line[a++] = buff[b++];
	line[ft_strlen(str) + ft_strlen(buff)] = '\0';
	free(str);
	return (line);
}

char	*ft_get_line(char *str)
{
	int		x;
	char	*line;

	x = 0;
	if (!str[x])
		return (NULL);
	while (str[x] && str[x] != '\n')
		x++;
	line = (char *)malloc(sizeof(char) * (x + 2));
	if (!line)
		return (NULL);
	x = 0;
	while (str[x] && str[x] != '\n')
	{
		line[x] = str[x];
		x++;
	}
	if (str[x] == '\n')
	{
		line[x] = str[x];
		x++;
	}
	line[x] = '\0';
	return (line);
}

char	*ft_update(char *str)
{
	char	*line;
	int		a;
	int		b;

	a = 0;
	while (str[a] && str[a] != '\n')
		a++;
	if (!str[a])
	{
		free(str);
		return (NULL);
	}
	line = (char *)malloc(sizeof(char) * (ft_strlen(str) - a + 1));
	if (!line)
	{
		free(str);
		return (NULL);
	}
	a++;
	b = 0;
	while (str[a])
		line[b++] = str[a++];
	line[b] = '\0';
	free(str);
	return (line);
}
