/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomasrpita <tomasrpita@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 11:44:50 by tpita-de          #+#    #+#             */
/*   Updated: 2019/11/18 06:32:31 by tomasrpita       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_result(const char *str, int i)
{
	size_t result;

	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	nc;
	int	result;

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
	return (result * nc);
}

int			ft_atoi(const char *str)
{
	unsigned long long	nmbr;
	char				check;

	nmbr = 0;
	while ((*str < 14 && *str > 8) || *str == 32)
		str++;
	check = '+';
	if (*str == '-' || *str == '+')
	{
		check = *str;
		str++;
	}
	while ((*str >= '0') && (*str <= '9'))
	{
		nmbr = nmbr * 10 + (*str - '0');
		str++;
	}
	if (nmbr > 9223372036854775807)
		return (check == '-' ? 0 : -1);
	return (check == '-' ? -nmbr : nmbr);
}

#include "libft.h"

int		ft_atoi(const char *str)
{
	int				i;
	long long int	result;
	long long int	neg;

	i = 0;
	neg = 1;
	result = 0;
	while (str[i] == 32 || str[i] == 10 || str[i] == 9 || str[i] == 12 ||
			str[i] == 13 || str[i] == 11)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i])
	{
		if (str[i] < 48 || 57 < str[i])
			return (result * neg);
		else
			result = (result * 10) + (long long int)(str[i] - '0');
		i++;
	}
	return (result * neg);
}