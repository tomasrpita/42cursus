/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomasrpita <tomasrpita@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 11:44:50 by tpita-de          #+#    #+#             */
/*   Updated: 2019/11/14 06:46:06 by tomasrpita       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_result(const char *str, int i)
{
	int result;

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
