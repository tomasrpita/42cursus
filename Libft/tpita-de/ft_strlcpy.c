/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpita-de <tpita-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 17:14:09 by tpita-de          #+#    #+#             */
/*   Updated: 2019/11/15 19:01:18 by tpita-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	j;
	size_t	k;

	k = 0;
	while (src[k] != '\0')
		k++;
	if (dstsize == 0)
		return (k);
	j = 0;
	while (src[j] != '\0' && j < dstsize)
	{
		dst[j] = src[j];
		j++;
	}
	dst[j] = '\0';
	return (k);
}
