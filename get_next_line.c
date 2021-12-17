/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 22:07:56 by mkoyamba          #+#    #+#             */
/*   Updated: 2021/12/17 14:49:21 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "wraloc.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	char	*tdst;
	char	*tsrc;
	size_t	a;

	if (!src && !dst && n != 0)
		return (NULL);
	tdst = (char *)dst;
	tsrc = (char *)src;
	a = 0;
	while (a < n)
	{
		tdst[a] = tsrc[a];
		a++;
	}
	return (dst);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*tdst;
	const char	*tsrc;

	tdst = (char *)dst;
	tsrc = (const char *)src;
	if (len == 0)
		return (dst);
	if (dst > src)
	{
		while (len - 1 > 0)
		{
			tdst[len - 1] = tsrc[len - 1];
			len--;
		}
		tdst[len - 1] = tsrc[len - 1];
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}

char	*line_in_extra(char *extra, size_t index)
{
	size_t	n;
	size_t	i;
	char	*result;

	n = 0;
	result = malloc((index + 1) * sizeof(char));
	if (!result)
		return (NULL);
	while (n < index)
	{
		result[n] = extra[n];
		n++;
	}
	result[n] = '\0';
	i = 0;
	ft_memmove(extra, extra + index, BUFFER_SIZE - index);
	ft_memset(extra + BUFFER_SIZE - index, 0, index);
	return (result);
}

char	*gnl_iter(char *result, char *extra, int fd)
{
	int		state;
	char	*temp;

	ft_memset(extra, 0, BUFFER_SIZE);
	state = read(fd, extra, BUFFER_SIZE);
	if ((state == 0 || state == -1) && result[0] == '\0')
		return (NULL);
	while (state)
	{
		if (gnl_check(extra))
		{
			temp = line_in_extra(extra, gnl_check(extra));
			if (!temp)
				return (0);
			result = ft_strjoin(result, temp);
			free(temp);
			return (result);
		}
		result = ft_strjoin(result, extra);
		ft_memset(extra, 0, BUFFER_SIZE);
		state = read(fd, extra, BUFFER_SIZE);
	}
	result = ft_strjoin(result, extra);
	ft_memset(extra, 0, BUFFER_SIZE);
	return (result);
}

char	*get_next_line(int fd)
{
	static char	extra[OPEN_MAX][BUFFER_SIZE];
	char		*result;
	char		*dup;

	if (BUFFER_SIZE <= 0 || !fd)
		return (NULL);
	result = ft_strdup("");
	dup = result;
	if (!result)
		return (NULL);
	if (!gnl_check(extra[fd]))
		result = ft_strjoin(result, extra[fd]);
	else
	{
		free(result);
		return (line_in_extra(extra[fd], gnl_check(extra[fd])));
	}
	result = gnl_iter(result, extra[fd], fd);
	if (result)
		return (result);
	//if (dup)
	//	free(dup);
	return (NULL);
}

#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;
	int		fddeux;
	int		n;
	char	*res;

	n = 0;
	fd = open("./test.txt", O_RDONLY);
	fddeux = open("./test2.txt", O_RDONLY);
	while (n < 5)
	{
		res = get_next_line(fd);
		//printf("|%s|", res);
		n++;
	}
}
