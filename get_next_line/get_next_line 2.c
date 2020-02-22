/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpita-de <tpita-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 13:01:22 by tpita-de          #+#    #+#             */
/*   Updated: 2020/02/22 19:42:53 by tpita-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line.h"

static void delete_node(t_get_nl **head, int fd)
{
	// t_get_nl *anterior;
	// t_get_nl *actual;
	// int		found;

	// actual = *tmp;
	// found = 0;
	// if (actual == NULL)
	// 	return ;
	// if (actual->next == NULL)
	// {
	// 	free(actual);
	// 	actual = NULL;
	// 	return ;
	// }
	// while (actual->next)
	// {
	// 	if (actual->fd == fd)
	// 		found = 1;
	// 	if (!found)
	// 		anterior = actual;
	// 	actual = actual->next;
	// }
	// anterior->next = actual->next;
	// free(actual);
	// actual = NULL;
	// return ;

	t_get_nl **x;
	t_get_nl *z;

	x = head;
	while (*x && (*x)->fd != fd)
		x = &(*x)->next;
	if (*x)
	{
		z = *x;
		*x = z->next;
		free(z);
		z = NULL;
	}

}

static char		*ft_strjoin_free(char *s1, char const *s2)
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
	free(s1);
	s1 = NULL;
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
			*line = ft_strdup_and_ft_memset(remnant, 0);
			ft_strdup_and_ft_memset(remnant, 1);
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
	// mem_read = 1;
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
	if (!p_n)
	{
		free(*remnant);
		*remnant = NULL;
		return (0);
	}
	return (1);
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
	int				result;

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
	result = get_line(tmp->fd, line, &tmp->remnant);
	if (result <= 0)
	{
		delete_node(&head, tmp->fd);
		// head = NULL;
	}
	return (result);
}

// int        main(void)
// {
//     char    *line;
//     int        fd;
//     // int        return_value;
//     int        num_lineas;


// 	num_lineas = 1;
// 	fd = open("1.txt", O_RDONLY);
//     while ((get_next_line(fd, &line)) == 1)
//     {
//         printf("%s\n", line);
//         free(line);
// 		line = NULL;
//         ++num_lineas;
//     }
// 	printf("%s\n", line);
// 	free(line);
// 	line = NULL;
//     printf("Numero de lineas: %d\n", num_lineas);
//     close(fd);

// 	num_lineas = 1;
// 	fd = open("3.txt", O_RDONLY);
//     while ((get_next_line(fd, &line)) == 1)
//     {
//         printf("%s\n", line);
//         free(line);
// 		line = NULL;
//         ++num_lineas;
//     }
// 	printf("%s\n", line);
// 	free(line);
//     line = NULL;
// 	printf("Numero de lineas: %d\n", num_lineas);
//     close(fd);

// 	return (0);



// }



