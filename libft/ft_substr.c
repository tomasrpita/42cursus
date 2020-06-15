/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomasrpita <tomasrpita@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 15:53:28 by tpita-de          #+#    #+#             */
/*   Updated: 2020/06/06 18:44:13 by tomasrpita       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*d;
	size_t	i;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	if (!(d = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (i < len)
	{
		d[i] = s[start + i];
		++i;
	}
	d[i] = '\0';
	return (d);
}
