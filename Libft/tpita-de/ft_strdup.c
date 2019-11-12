/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpita-de <tpita-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 06:08:19 by tomasrpita        #+#    #+#             */
/*   Updated: 2019/11/12 21:47:51 by tpita-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include 'libft.h'

char	*ft_strdup(const char *s1)
{
	int		size;
	char	*s2;
	int		i;

	size = strlen(s1);
	if (!(s2 = (char *)calloc((size + 1), sizeof(char))))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	/* prueba quitando la siguiente linea con calloc no hace falta */
	s2[i] = '\0';
	return (s2);
}