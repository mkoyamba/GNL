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

void	*gnl_iter(int fd, char *result, char **extra)
{

}

char	*get_next_line(int fd)
{
	char		*result;
	static char	extra[OPEN_MAX][BUFFER_SIZE];

	result = malloc(BUFFER_SIZE * sizeof(char));
	if (!result)
		return (NULL);
	gnl_iter(fd, result, extra);
	return (result);
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
