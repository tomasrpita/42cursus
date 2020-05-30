/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpita-de <tpita-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 11:41:28 by tpita-de          #+#    #+#             */
/*   Updated: 2020/05/11 19:53:50 by tpita-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>

typedef	struct	s_gnl
{
	int				fd;
	int				eof;
	char			*remnant;
	struct s_gnl	*next;
}				t_gnl;

int				get_next_line(int fd, char **line);
char			*str_join(char *str1, char *str2, char *str_free);
char			*sub_str(char const *s, unsigned int start, size_t len);

#endif
