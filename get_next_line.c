/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 22:07:56 by mkoyamba          #+#    #+#             */
/*   Updated: 2021/12/06 16:34:32 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static size_t	ft_strlen(char *s)
{
	size_t	n;

	n = 0;
	while (s[n])
		n++;
	return (n);
}

static char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	int		n;
	int		a;

	n = 0;
	a = 0;
	result = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	while (s1[a] != '\0')
	{
		result[n] = s1[a];
		n++;
		a++;
	}
	a = 0;
	while (s2[a] != '\0')
	{
		result[n] = s2[a];
		n++;
		a++;
	}
	result[n] = '\0';
	return (result);
}

static size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	n;

	n = 0;
	while (src[n] != '\0' && n < dstsize - 1 && dstsize != 0)
	{
		dst[n] = src[n];
		n++;
	}
	if (dstsize != 0)
		dst[n] = '\0';
	return ((size_t)ft_strlen(src));
}

static char	*sort_buf(char *buf, size_t n, int fd)
{
	
}

char	*get_next_line(int fd)
{
	size_t			n;
	char			*result;
	char			buf[BUFFER_SIZE + 1];
	static t_struct	save[OPEN_MAX];
	size_t			state;

	n = 0;
	state = read(fd, buf, BUFFER_SIZE);
	buf[state] = '\0';
	if (state == 0)
		return (NULL);
	while (n < state && buf[n] != '\n')
		n++;
	if (buf[n] == '\n')
		return (sort_buf(buf, n, fd));
	if ()
}

#include <fcntl.h>

int	main(void)
{
	int		fd;
	int		n;

	n = 0;
	fd = open("./test.txt", O_RDONLY);
	while (n < 4)
	{
		printf("%s", get_next_line(fd));
		n++;
	}
	return (0);
}
