/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpita-de <tpita-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 18:48:02 by tpita-de          #+#    #+#             */
/*   Updated: 2019/11/12 21:40:36 by tpita-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include 'libft.h'

char	*ft_strnstr(const char *haystack, const char *needle, long int len)
{
	int i;
	int j;
	int k;

	if (needle[0] == '\0')
		return ((char *)haystack);
	k = 0;
	i = 0;
	while (haystack[i] && i < len)
	{
		j = 0;
		if (haystack[i] == needle[j])
		{
			k = i;
			while (haystack[k] == needle[j] && needle[j] && k < len)
			{
				k++;
				j++;
			}
			if (needle[j] == '\0')
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}