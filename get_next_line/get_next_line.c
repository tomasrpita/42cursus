/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomasrpita <tomasrpita@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 11:41:28 by tomasrpita        #+#    #+#             */
/*   Updated: 2020/05/11 19:53:50 by tomasrpita       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_gnl	*new_node(int fd)
{
	t_gnl		*new;

	if (!(new = (t_gnl *)malloc(sizeof(t_gnl))))
		return (NULL);
	*new = (t_gnl){ .fd = fd, .eof = 0, .next = NULL};
	if (!(new->remnant = str_join("", "", 0)))
		free(new);
	return (!(new->remnant) ? NULL : new);
}

static t_gnl	*get_node(t_gnl **hnode, int fd)
{
	t_gnl	*an;

	an = *hnode;
	while ((an && !(an->fd == fd)))
	{
		if (an->next == NULL)
		{
			if (!(an->next = new_node(fd)))
				return (NULL);
		}
		an = an->next;
	}
	return (an);
}

static int		del_node(t_gnl **fnode, int fd)
{
	t_gnl **x;
	t_gnl *z;

	x = fnode;
	while (*x && (*x)->fd != fd)
		x = &(*x)->next;
	if (*x)
	{
		z = *x;
		*x = z->next;
		free(z->remnant);
		free(z);
	}
	return (0);
}

static int		read_line(t_gnl *an)
{
	int		ret;
	int		i;
	int		j;
	char	buffer[BUFFER_SIZE + 1];

	j = 0;
	while (an->remnant && an->remnant[j] && an->remnant[j] != '\n')
		j++;
	if (an->remnant && (an->remnant[j] == '\n'))
		return (j);
	while ((ret = read(an->fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[ret] = 0;
		if (!(an->remnant = str_join(an->remnant, buffer, an->remnant)))
			return (-1);
		i = -1;
		while (++i < ret)
			if (buffer[i] == '\n')
				return (j + i);
		j += ret;
	}
	if (ret == 0 && an && an->remnant && an->remnant[j] == 0)
		an->eof = 1;
	return (ret == -1 ? -1 : j);
}

int				get_next_line(int fd, char **line)
{
	static t_gnl	*hnode;
	t_gnl			*an;
	int				index;

	if (!line || fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	if (!hnode)
	{
		if (!(hnode = new_node(fd)))
			return (-1);
	}
	if (!(an = get_node(&hnode, fd)))
		return (-1);
	index = read_line(an);
	if (index == -1 || !(*line = sub_str(an->remnant, 0, index)) || an->eof)
		return ((del_node(&hnode, fd) || 1) * (!*line || index == -1 ? -1 : 0));
	if (!(an->remnant = str_join(an->remnant + index + 1, "", an->remnant)))
		return ((del_node(&hnode, fd) || 1) * -1);
	return (1);
}
