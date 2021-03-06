/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpita-de <tpita-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 18:16:47 by tpita-de          #+#    #+#             */
/*   Updated: 2019/11/15 19:18:51 by tpita-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *pos;

	pos = (0);
	while (*s)
	{
		if ((unsigned char)*s == (unsigned char)c)
			pos = (char *)s;
		s++;
	}
	if (pos)
		return (pos);
	if (c == '\0')
		return ((char*)s);
	return (NULL);
}
