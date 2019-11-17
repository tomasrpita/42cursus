/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpita-de <tpita-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 13:39:36 by tpita-de          #+#    #+#             */
/*   Updated: 2019/11/17 17:01:17 by tpita-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char    **ft_crtmtx(size_t row, size_t col)
{
	size_t        i;
	size_t        j;
	char        **matrix;

	if (row < 0 || col < 0)
		return (NULL);
	if ((matrix = (char **)malloc(row * sizeof(char *))) == NULL)
		return (NULL);
	i = 0;
	while (i < row)
	{
		if ((matrix[i] = (char *)malloc((col + 1)* sizeof(char))) == NULL)
			return (NULL);
		j = 0;
		while (j <= col)
		{
			matrix[i][j] = 0;
			++j;
		}
		++i;
	}
	return (matrix);
}

char    **ft_split(char const *s, char c)
{
	size_t    i;
	size_t    row;
	size_t    col;
	size_t    count;
	char    **matrix;
	size_t    j;

	i = 0;
	row = 0;
	if (s[i] != c)
		++row;
	++i;
	while (s[i])
	{

		if (s[i] == c && s[i + 1] != c && s[i + 1] != 0)
			++row;
		++i;
	}
	i = 0;
	col = 0;
	j = -1;
	while (s[i])
	{
		++j;
		count = 0;
		while (s[j] != c && s[j])
		{
		  ++count;
		  ++j;
		}
		if (count > col)
		  col = count;
		i = j;
	}
	matrix = ft_crtmtx(row, col);
	return (matrix);
}
