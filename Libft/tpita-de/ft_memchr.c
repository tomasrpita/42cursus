/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpita-de <tpita-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 15:54:20 by tpita-de          #+#    #+#             */
/*   Updated: 2019/11/12 21:23:13 by tpita-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include 'libft.h'

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *t_s;

	t_s = (unsigned char *)s;
	while (n > 0)
	{
		if (*t_s == (unsigned char)c)
			return ((void *)t_s);
		t_s++;
		n--;
	}
	return (NULL);
}