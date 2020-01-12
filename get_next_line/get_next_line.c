/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpita-de <tpita-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 13:01:22 by tpita-de          #+#    #+#             */
/*   Updated: 2020/01/12 15:24:55 by tpita-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*ft_strjoin_up(char const *s1, char const *s2)
{
	size_t	size1;
	size_t	size2;
	char	*d;
	size_t	i;

	if (!s2 || !s1)
		return (NULL);
	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	if (!(d = (char *)malloc((size1 + size2 + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (i < size1)
	{
		d[i] = s1[i];
		++i;
	}
	while (i < (size2 + size1))
	{
		d[i] = s2[i - size1];
		++i;
	}
	d[i] = '\0';
	free((void *)s1);
	return (d);
}

static void		*ft_memset(void *b, int c, size_t len)
{
	char	*t_str;

	t_str = b;
	while (len)
	{
		*t_str = c;
		t_str++;
		len--;
	}
	return (b);
}

static char		*check_remainder(char *remainder, char **line)
{
	char	*p_n;

	p_n = NULL;
	if (remainder)
	{
		if ((p_n = ft_strchr(remainder, '\n')))
		{
			*p_n = '\0';
			*line = ft_strdup(remainder);
			ft_strcpy(remainder, ++p_n);
		}
		else
		{
			*line = ft_strdup(remainder);
			ft_memset(remainder, '\0', ft_strlen(remainder));
		}
	}
	else
		*line = ft_strdup("\0\0");
	return (p_n);
}

int				get_next_line(int fd, char **line)
{
	static char	*remainder;
	char		buf[BUFFER_SIZE + 1];
	ssize_t		mem_read;
	char		*p_n;

	if (read(fd, NULL, 0) < 0 || line == NULL || BUFFER_SIZE == 0)
		return (-1);
	p_n = check_remainder(remainder, line);
	mem_read = 1;
	while (!p_n && (mem_read = read(fd, buf, BUFFER_SIZE)))
	{
		buf[mem_read] = '\0';
		if ((p_n = ft_strchr(buf, '\n')))
		{
			*p_n = '\0';
			++p_n;
			if (fd != 0)
				remainder = ft_strdup(p_n);
		}
		*line = ft_strjoin_up(*line, buf);
	}
	if (!mem_read)
		return (0);
	return ((mem_read || (ft_strlen(*line) && ft_strlen(remainder))) ? 1 : 0);
}
