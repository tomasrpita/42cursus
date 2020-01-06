/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpita-de <tpita-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 13:01:22 by tpita-de          #+#    #+#             */
/*   Updated: 2020/01/06 17:37:13 by tpita-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_get_next_line
{
	int						fd;
	char					*remainder;
	struct s_get_next_line	*next;
}				t_get_nl;

int				get_next_line(int fd, char **line);
size_t			ft_strlen(const char *s);
void			*ft_calloc(size_t count, size_t size);
char			*ft_strdup_and_ft_memset(char *s1, int flag);
char			*ft_strchr(const char *s, int c);
char			*ft_strcpy(char *dest, char *src);

#endif
