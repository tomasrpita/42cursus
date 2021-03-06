/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpita-de <tpita-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 16:41:06 by tpita-de          #+#    #+#             */
/*   Updated: 2019/11/29 19:59:55 by tpita-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char		*t_str1;
	unsigned const char		*s_str2;

	t_str1 = (unsigned const char *)s1;
	s_str2 = (unsigned const char *)s2;
	while (n)
	{
		if (*t_str1 != *s_str2)
			return (*t_str1 - *s_str2);
		t_str1++;
		s_str2++;
		n--;
	}
	return (0);
}
