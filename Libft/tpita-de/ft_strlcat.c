/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpita-de <tpita-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 19:01:03 by tpita-de          #+#    #+#             */
/*   Updated: 2019/11/30 17:30:22 by tpita-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	orig;
	size_t	len_final;

	orig = dstsize + ft_strlen(src);
	len_final = 0;
	while (*dst && dstsize > 0)
	{
		dst++;
		dstsize--;
		len_final++;
	}
	if (dstsize < 1)
		return (orig);
	while (*src && --dstsize > 0)
	{
		*dst++ = *src++;
		len_final++;
	}
	while (*src++)
		len_final++;
	*dst = '\0';
	return (len_final);
}
