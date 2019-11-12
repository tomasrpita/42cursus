/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpita-de <tpita-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 17:46:36 by tpita-de          #+#    #+#             */
/*   Updated: 2019/11/12 21:32:04 by tpita-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include 'libft.h'

char	*ft_strchr(const char *s, int c)
{
	while (s)
	{
		if ((unsigned char)*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}
