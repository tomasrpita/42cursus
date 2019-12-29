/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpita-de <tpita-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 13:00:17 by tpita-de          #+#    #+#             */
/*   Updated: 2019/12/28 17:49:59 by tpita-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ret;
	size_t	i;

	if (count == 0)
		count = 1;
	i = 0;
	if (size)
	{
		if (NULL == (ret = malloc(count * size)))
			return (NULL);
		while (i < (count * size))
		{
			((char *)ret)[i] = 0;
			i++;
		}
		return (ret);
	}
	if (NULL == (ret = malloc(count)))
		return (NULL);
	while (i < count)
	{
		((char *)ret)[i] = 0;
		i++;
	}
	return (ret);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	int		size;
	char	*s2;
	int		i;

	if (!s1)
		return (NULL);
	size = ft_strlen(s1);
	if (!(s2 = ft_calloc((size + 1), sizeof(char))))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	return (s2);
}

char	*ft_strjoin_up(char const *s1, char const *s2)
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
	free((void *)s1);
	d[i] = '\0';
	return (d);
}

char	*ft_strchr(const char *s, int c)
{

	while (*s)
	{
		if ((unsigned char)*s == (unsigned char)c)
			return((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char*)s);
	return (NULL);
}

char	*ft_strnew(size_t size)
{
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	str[size] = '\0';
	while (size--)
		str[size] = '\0';
	return (str);
}

char *ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	*ft_memset(void *b, int c, size_t len)
{
	char *t_str;

	t_str = b;
	while (len)
	{
		*t_str = c;
		t_str++;
		len--;
	}
	return (b);
}