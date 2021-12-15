/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 22:07:56 by mkoyamba          #+#    #+#             */
/*   Updated: 2021/12/14 12:00:14 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*push_extra_l(char **extra, int fd, size_t check)
{
	size_t	n;
	size_t	i;
	char	*result;

	result = malloc((check + 1) * sizeof(char));
	if (!result)
		return (NULL);
	if (!check)
	{
		result[0] = 0;
		return (result);
	}
	n = 0;
	while (n < check)
	{
		result[n] = extra[fd][n];
		n++;
	}
	result[n] = '\0';
	i = 0;
	ft_memmove(extra[fd], extra[fd] + check, BUFFER_SIZE - check);
	ft_memset(extra[fd] + (BUFFER_SIZE - check - 1), 0, check);
	return (result);
}

char	*get_next_line(int fd)
{
	static char	extra[FOPEN_MAX][BUFFER_SIZE];
	size_t	state;
	char	*result;

	if (gnl_check(extra[fd]))
		return (push_extra_l((char **)extra, fd, gnl_check(extra[fd])));
	result = push_extra_l((char **)extra, fd, gnl_check(extra[fd]));
	if (!result)
		return (NULL);
	state = BUFFER_SIZE;
	while (state == BUFFER_SIZE)
	{
		ft_memset(extra[fd], 0, BUFFER_SIZE);
		state = read(fd, extra[fd], BUFFER_SIZE);
		printf("%zu\n", state);
		if (state == 0)
			break ;
		else if (gnl_check(extra[fd]))
		{
			printf("\\n\n");
			result = ft_strjoin(result,
				push_extra_l((char **)extra, fd, gnl_check(extra[fd])));
			break ;
		}
		printf("test\n");
		ft_strjoin(result, extra[fd]);
	}
	return(result);
}

#include <fcntl.h>

int	main(void)
{
	int		fd;
	int		n;
	char	*res;

	n = 0;
	fd = open("./test.txt", O_RDONLY);
	res = get_next_line(fd);
	while (res)
	{
		printf("%s", res);
		res = get_next_line(fd);
		n++;
	}
	return (0);
}
