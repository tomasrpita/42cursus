/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpita-de <tpita-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 13:01:22 by tpita-de          #+#    #+#             */
/*   Updated: 2020/01/26 13:14:24 by tpita-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line_bonus.h"

static char		*ft_strjoin_free(char const *s1, char const *s2)
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
	// free((void *)s1);
	return (d);
}

static char		*check_remnant(char *remnant, char **line)
{
	char		*p_n;

	p_n = NULL;
	if (remnant)
	{
		if ((p_n = ft_strchr(remnant, '\n')))
		{
			*p_n = '\0';
			*line = ft_strdup_and_ft_memset(remnant, 0);
			ft_strcpy(remnant, ++p_n);
		}
		else
		{
			*line = ft_strdup_and_ft_memset(remnant, 1);
		}
	}
	else
		*line = ft_strdup_and_ft_memset("", 0);
	return (p_n);
}

static int		get_line(int fd, char **line, char **remnant)
{
	char		buf[BUFFER_SIZE + 1];
	ssize_t		mem_read;
	char		*p_n;

	p_n = check_remnant(*remnant, line);
	mem_read = 1;
	while (!p_n && (mem_read = read(fd, buf, BUFFER_SIZE)))
	{
		buf[mem_read] = '\0';
		if ((p_n = ft_strchr(buf, '\n')))
		{
			*p_n = '\0';
			++p_n;
			if (fd != 0)
				*remnant = ft_strdup_and_ft_memset(p_n, 0);
		}
		if (!(*line = ft_strjoin_free(*line, buf)) || mem_read < 0)
			return (-1);
	}
	if (!mem_read)
		return (0);
	return ((mem_read || (ft_strlen(*line) && ft_strlen(*remnant))) ? 1 : 0);
}

static t_get_nl	*new_linked_list_el(int fd)
{
	t_get_nl		*new;

	new = (t_get_nl *)malloc(sizeof(t_get_nl));
	new->fd = fd;
	new->remnant = NULL;
	new->next = NULL;
	return (new);
}

int				get_next_line(int fd, char **line)
{
	static t_get_nl *head;
	t_get_nl		*tmp;

	if (read(fd, NULL, 0) < 0 || line == NULL || BUFFER_SIZE < 1)
		return (-1);
	if (head == NULL)
		head = new_linked_list_el(fd);
	tmp = head;
	while (tmp->fd != fd)
	{
		if (tmp->next == NULL)
			tmp->next = new_linked_list_el(fd);
		tmp = tmp->next;
	}
	return (get_line(tmp->fd, line, &tmp->remnant));
}


