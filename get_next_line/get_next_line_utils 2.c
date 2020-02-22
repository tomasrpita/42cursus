/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpita-de <tpita-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 13:00:17 by tpita-de          #+#    #+#             */
/*   Updated: 2020/02/22 19:45:23 by tpita-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

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

char	*ft_strdup_and_ft_memset(char *s1, int flag)
{
	int		size;
	char	*s2;
	int		i;

	if (!s1)
		return (NULL);
	size = ft_strlen(s1);
	if (flag)
	{
		while (size > 0)
		{
			size--;
			s1[size] = '\0';
		}
		return (s1);
	}
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

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if ((unsigned char)*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char*)s);
	return (NULL);
}

char	*ft_strcpy(char *dest, char *src)
{
	int		i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
