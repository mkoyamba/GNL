/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 15:30:39 by mkoyamba          #+#    #+#             */
/*   Updated: 2021/12/16 00:35:26 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdio.h>

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <limits.h>

char	*gnl_last(char *result, char *extra);
char	*ft_strdup(char *s1);
char	*push_extra_l(char *extra, size_t check);
char	*get_next_line(int fd);
size_t	ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
void	*ft_memset(void *b, int c, size_t len);
size_t	gnl_check(char *buf);

#endif