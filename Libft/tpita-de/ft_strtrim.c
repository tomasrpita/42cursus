/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpita-de <tpita-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 17:24:27 by tpita-de          #+#    #+#             */
/*   Updated: 2019/11/17 11:44:58 by tpita-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_sizetrim(char const *s1, char const *set)
{
	size_t i;
	size_t j;
	size_t size;

	size = ft_strlen(s1);
	i = 0;
	while (set[i])
	{
		j = 0;
		while (s1[j])
		{
			if (s1[j] == set[i])
				--size;
			++j;
		}
		++i;
	}
	return (size);
}

static char		*ft_trimchar(char *s, char const c)
{
	size_t	i;
	size_t	j;
	char	*s2;
	size_t	size;

	size = ft_sizetrim(s, &c);
	if (NULL == (s2 = (char *)malloc((size + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			s2[j] = s[i];
			++j;
		}
		++i;
	}
	s2[j] = '\n';
	return (s2);
}

static char		*ft_trimcharb(char *s, char const c)
{
	size_t	i;
	size_t	j;
	char	*s2;
	size_t	size;

	size = ft_sizetrim(s, &c);
	if (NULL == (s2 = (char *)malloc((size + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			s2[j] = s[i];
			++j;
		}
		++i;
	}
	s2[j] = '\n';
	return (s2);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*copy;
	size_t	s1size;
	size_t	i;

	s1size = ft_strlen(s1);
	if (NULL == (copy = (char *)malloc((s1size + 1) * sizeof(char))))
		return (NULL);
	ft_strlcpy(copy, s1, s1size);
	i = 0;
	while (set[i])
	{
		copy = ft_trimchar(copy, set[i]);
		++i;
	}
	return (copy);
}
