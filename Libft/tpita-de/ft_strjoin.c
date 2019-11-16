/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpita-de <tpita-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 16:39:09 by tpita-de          #+#    #+#             */
/*   Updated: 2019/11/16 17:15:38 by tpita-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size1;
	size_t	size2;
	char	*d;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	if (NULL == (d = (char *)malloc((size1 + size2 + 1) * sizeof(char))))
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
	return (d);
}
