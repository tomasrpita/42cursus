/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomasrpita <tomasrpita@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 16:41:06 by tpita-de          #+#    #+#             */
/*   Updated: 2019/11/16 20:34:58 by tomasrpita       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char		*t_str1;
	unsigned const char		*s_str2;

	t_str1 = (unsigned const char *)s1;
	s_str2 = (unsigned const char *)s2;
	if (*t_str1 == '\0' || *s_str2 == '\0')
		return (0);
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