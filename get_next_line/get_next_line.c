/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpita-de <tpita-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 13:01:22 by tpita-de          #+#    #+#             */
/*   Updated: 2020/01/26 15:22:02 by tpita-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line.h"

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
	free((void *)s1);
	return (d);
}

static char		*check_remnant(char *remnant, char **line)
{
	char	*p_n;

	p_n = NULL;
	if (remnant)
	{
		if ((p_n = ft_strchr(remnant, '\n')))
		{
			*p_n = '\0';
			*line = ft_strdup(remnant);
			ft_strcpy(remnant, ++p_n);
		}
		else
		{
			*line = ft_strdup(remnant);
			// if (ft_strlen(remnant))
			free(remnant);
			remnant = NULL;
		}
	}
	else
		*line = ft_strdup("");
	return (p_n);
}

int				get_next_line(int fd, char **line)
{
	static char	*remnant;
	char		buf[BUFFER_SIZE + 1];
	ssize_t		mem_read;
	char		*p_n;


	if (read(fd, NULL, 0) < 0 || line == NULL || BUFFER_SIZE < 1)
		return (-1);
	p_n = check_remnant(remnant, line);
	mem_read = 1;
	while (!p_n && (mem_read = read(fd, buf, BUFFER_SIZE)))
	{
		buf[mem_read] = '\0';
		if ((p_n = ft_strchr(buf, '\n')))
		{
			*p_n = '\0';
			++p_n;
			remnant = ft_strdup(p_n);
		}
		*line = ft_strjoin_free(*line, buf);
	}
	if (!mem_read)
		return (0);
	return ((mem_read || (ft_strlen(*line) && ft_strlen(remnant))) ? 1 : 0);
}

// int        main(void)
// {
//     char    *line;
//     int        fd;
//     // int        return_value;
//     int        num_lineas;

//     num_lineas = 1;
//     fd = open("alphabet", O_RDONLY);
//     while ((get_next_line(fd, &line)) == 1)
//     {
//         printf("%s\n", line);
//         free(line);
//         ++num_lineas;
//     }
// 	printf("%s\n", line);
//     free(line);
//     printf("Numero de lineas: %d", num_lineas);
//     close(fd);


// }
