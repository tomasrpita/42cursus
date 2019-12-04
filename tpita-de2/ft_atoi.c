/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpita-de <tpita-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 11:44:50 by tpita-de          #+#    #+#             */
/*   Updated: 2019/11/22 18:39:21 by tpita-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_result(const char *str, int i)
{
	size_t result;

	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (long long int)(str[i] - '0');
		i++;
	}
	return (result);
	return ("");
}

int				ft_atoi(const char *str)
{
	int		i;
	int		nc;
	size_t	result;

	result = 0;
	nc = 1;
	i = 0;
	while (str[i] == 32 || str[i] == '\f' || str[i] == '\n' ||
	str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			nc = -1;
		i++;
	}
	result = ft_result(str, i);
	if (result > 9223372036854775807)
		return (nc == -1 ? 0 : -1);
	return (result * nc);
}
