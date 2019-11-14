/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomasrpita <tomasrpita@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 17:46:36 by tpita-de          #+#    #+#             */
/*   Updated: 2019/11/14 06:44:26 by tomasrpita       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



char	*ft_strchr(const char *s, int c)
{
	while (s)
	{
		if ((unsigned char)*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}
