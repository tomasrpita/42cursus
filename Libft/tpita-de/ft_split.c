/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpita-de <tpita-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 13:39:36 by tpita-de          #+#    #+#             */
/*   Updated: 2019/11/23 14:54:52 by tpita-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	if (s[i] == c)
		++words;
	++i;
	while (s[i])
	{

		if (s[i] == c && s[i + 1] != c && s[i + 1] != 0)
			++words;
		++i;
	}
	return (words);
}

static char	*ft_malloc_word(char const *s, char c)
{
	char	*word;
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
		++i;
	word = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (s[i] && s[i] != c)
	{
		word[i] = s[i];
		++i;
	}
	word[i] = '\0';
	return (word);
}

char		**ft_split(char const *s, char c)
{
	size_t	words;
	char	**matrix;
	size_t	i;

	if (s == NULL)
		return (NULL);
	words = ft_count_words(s, c);
	if ((matrix = (char **)malloc((words + 1) * sizeof(char *))) == NULL)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			++s;
		if (*s && *s != c)
		{
			matrix[i] = ft_malloc_word(s, c);
			++i;
			while (*s && *s != c)
				++s;
		}
	}
	matrix[i] = NULL;
	return (matrix);
}
