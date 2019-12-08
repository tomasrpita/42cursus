/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpita-de <tpita-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 13:22:17 by tpita-de          #+#    #+#             */
/*   Updated: 2019/11/24 13:40:44 by tpita-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*lastitem;

	lastitem = lst;
	if (lastitem)
	{
		while (lastitem->next)
		{
			lastitem = lastitem->next;
		}
	}
	return (lastitem);
}
