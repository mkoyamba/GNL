/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 22:07:56 by mkoyamba          #+#    #+#             */
/*   Updated: 2021/12/16 00:46:08 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

char	*gnl_last(char *result, char *extra)
{
	if (!result[0])
	{
		free (result);
		return (NULL);
	}
	result = ft_strjoin(result, extra);
	ft_memset(extra, 0, BUFFER_SIZE);
	return (result);
}

char	*ft_strdup(char *s1)
{
	char	*dest;
	int		a;

	dest = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	a = 0;
	while (s1[a] != '\0')
	{
		dest[a] = s1[a];
		a++;
	}
	dest[a] = '\0';
	return (dest);
}

char	*push_extra_l(char *extra, size_t check)
{
	size_t	n;
	size_t	i;
	char	*result;

	if (check == 0)
		return (ft_strdup(""));
	result = malloc((check + 1) * sizeof(char));
	if (!result)
		return (NULL);
	n = 0;
	i = 0;
	while (n < check)
	{
		result[n] = extra[n];
		n++;
	}
	result[n] = '\0';
	while (n < BUFFER_SIZE)
	{
		extra[i] = extra[n];
		i++;
		n++;
	}
	ft_memset(extra + i, 0, BUFFER_SIZE - i);
	return (result);
}

char	*get_next_line(int fd)
{
	static char	extra[FOPEN_MAX][BUFFER_SIZE];
	size_t		state;
	char		*result;

	if (gnl_check(extra[fd]))
		return (push_extra_l(extra[fd], gnl_check(extra[fd])));
	result = push_extra_l(extra[fd], gnl_check(extra[fd]));
	if (!result)
		return (NULL);
	state = BUFFER_SIZE;
	ft_memset(extra[fd], 0, BUFFER_SIZE);
	while (state == BUFFER_SIZE)
	{
		ft_memset(extra[fd], 0, BUFFER_SIZE);
		state = read(fd, extra[fd], BUFFER_SIZE);
		if (state == 0 && !result[0])
			return (gnl_last(result, extra[fd]));
		else if (gnl_check(extra[fd]) != 0)
		{
			result = ft_strjoin(result,
					push_extra_l(extra[fd], gnl_check(extra[fd])));
			break ;
		}
		result = ft_strjoin(result, extra[fd]);
	}
	return (result);
}

int	main(void)
{
	int		fd;
	int		n;
	char	*res;

	n = 0;
	fd = open("./test.txt", O_RDONLY);
	res = get_next_line(fd);
	printf("%s", res);
	res = get_next_line(fd);
	printf("%s", res);
	res = get_next_line(fd);
	printf("%s", res);
	res = get_next_line(fd);
	printf("%s", res);
	return (0);
}
