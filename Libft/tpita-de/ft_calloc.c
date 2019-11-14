/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpita-de <tpita-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 20:52:09 by tpita-de          #+#    #+#             */
/*   Updated: 2019/11/14 21:00:47 by tpita-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ret;
	size_t	i;

	if (count == 0 || size == 0)
		return (NULL);
	i = 0;
	ret = malloc(count * size);
	while (i < (count * size))
	{
		((char *)ret)[i] = 0;
		i++;
	}
	return (ret);

}