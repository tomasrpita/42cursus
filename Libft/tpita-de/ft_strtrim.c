/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpita-de <tpita-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 17:24:27 by tpita-de          #+#    #+#             */
/*   Updated: 2019/11/16 19:30:58 by tpita-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	s1size;
	char	*copy;
	size_t	scopy;
	size_t	i;
	size_t	j;
	size_t	k;

	s1size = ft_strlen(s1);
	if (s1size == 0)
		return (NULL);
	i = 0;
	scopy = 0;
	while (set[i])
	{
		j = 0;
		while (s1[j])
		{
			if ((unsigned char)s1[j] == (unsigned char)set[i])
				++scopy;
			++j;
		}
		++i;
	}
	if (NULL == (copy = (char *)malloc((s1size + 1) * sizeof(char))))
		return (NULL);
	ft_strlcpy(copy, s1, s1size);
	i = 0;
	while (set[i])
	{
		j = 0;
		k = 0;
		while (s1[j])
		{
			if ((unsigned char)copy[j] != (unsigned char)set[i])
			{

				copy[k] = copy[j];
				++k;
			}
			++j;
		}
		++i;
	}
	copy[k] = '\0';
	return (copy);
}
