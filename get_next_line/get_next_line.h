/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomasrpita <tomasrpita@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 13:01:22 by tpita-de          #+#    #+#             */
/*   Updated: 2020/05/10 18:17:01 by tomasrpita       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>

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
