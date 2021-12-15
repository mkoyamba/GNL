/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 09:32:57 by mkoyamba          #+#    #+#             */
/*   Updated: 2021/12/16 00:35:51 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	n;

	n = 0;
	if (!s)
		return (0);
	while (s[n])
		n++;
	return (n);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	int		n;
	int		a;

	n = 0;
	a = 0;
	result = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!result)
		return (NULL);
	while (s1 && s1[a])
	{
		result[n] = s1[a];
		n++;
		a++;
	}
	a = 0;
	while (s2 && s2[a])
	{
		result[n] = s2[a];
		n++;
		a++;
	}
	result[n] = '\0';
	free(s1);
	return (result);
}

void	*ft_memset(void *b, int c, size_t len)
{
	char			*result;
	unsigned int	n;

	n = 0;
	result = (char *)b;
	while (n < len)
	{
		result[n] = (unsigned char)c;
		n++;
	}
	return (b);
}

size_t	gnl_check(char *buf)
{
	size_t	n;

	n = 0;
	if (!buf)
		return (0);
	while (n < ft_strlen(buf))
	{
		if (buf[n] == '\n')
			return (n + 1);
		n++;
	}
	if (buf[0])
		return (n + 1);
	return (0);
}
