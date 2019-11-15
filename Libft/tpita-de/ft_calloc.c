/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpita-de <tpita-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 20:52:09 by tpita-de          #+#    #+#             */
/*   Updated: 2019/11/15 19:34:16 by tpita-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ret;
	size_t	i;

	if (count == 0)
		return (NULL);
	i = 0;
	if (size)
	{
		if (NULL == (ret = malloc(count * size)))
			return (NULL);
		while (i < (count * size))
		{
			((char *)ret)[i] = 0;
			i++;
		}
		return (ret);
	}
	if (NULL == (ret = malloc(count)))
		return (NULL);
	while (i < count)
	{
		((char *)ret)[i] = 0;
		i++;
	}
	return (ret);
}
