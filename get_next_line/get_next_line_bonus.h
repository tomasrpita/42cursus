/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpita-de <tpita-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 13:01:22 by tpita-de          #+#    #+#             */
/*   Updated: 2020/01/03 14:08:32 by tpita-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int     get_next_line(int fd, char **line);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
char	*ft_strjoin_up(char const *s1, char const *s2);
char    *ft_strchr(const char *s, int c);
char	*ft_strnew(size_t size);
char    *ft_strcpy(char *dest, char *src);
void	*ft_memset(void *b, int c, size_t len);

#endif