/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpita-de <tpita-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 18:48:02 by tpita-de          #+#    #+#             */
/*   Updated: 2019/11/30 18:25:56 by tpita-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *h, const char *n, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	if (n[0] == '\0')
		return ((char *)h);
	k = 0;
	i = 0;
	while (h[i] && i < len)
	{
		j = 0;
		if (h[i] == n[j])
		{
			k = i;
			while (h[k] == n[j] && n[j] && k < len)
			{
				k++;
				j++;
			}
			if (n[j] == '\0')
				return ((char *)&h[i]);
		}
		i++;
	}
	return (NULL);
}
