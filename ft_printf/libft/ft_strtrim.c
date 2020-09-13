/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpita-de <tpita-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 17:24:27 by tpita-de          #+#    #+#             */
/*   Updated: 2020/08/29 15:05:48 by tpita-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strndup(const char *s, size_t n)
{
	char			*res;
	unsigned int	i;

	i = 0;
	res = malloc(sizeof(char) * (n + 1));
	if (res == NULL)
		return (NULL);
	while (i < n)
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	const char *start;
	const char *end;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = s1;
	while (ft_strchr(set, *start) && *start)
		start++;
	if (start == (void *)0)
		return (ft_strdup(""));
	end = s1;
	while (*(end + 1))
		++end;
	while (ft_strchr(set, *end) && end > s1)
		--end;
	if (end < start)
		return (ft_strdup(""));
	return (ft_strndup(start, (end - start) + 1));
}
