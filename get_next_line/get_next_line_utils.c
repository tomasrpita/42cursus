/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpita-de <tpita-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 11:41:28 by tpita-de          #+#    #+#             */
/*   Updated: 2020/05/11 19:53:50 by tpita-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*str_join(char *str1, char *str2, char *str_free)
{
	int		len_str1;
	int		len_str2;
	char	*str;
	int		i;

	len_str1 = 0;
	while (str1[len_str1])
		++len_str1;
	len_str2 = 0;
	while (str2[len_str2])
		++len_str2;
	if (!(str = (char *)malloc(sizeof(char) * (len_str1 + len_str2 + 1))))
		return (NULL);
	i = -1;
	while (str1[++i])
		str[i] = str1[i];
	i = -1;
	while (str2[++i])
		str[len_str1 + i] = str2[i];
	str[len_str1 + i] = '\0';
	if (str_free)
		free(str_free);
	return (str);
}

char		*sub_str(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		slen;
	int		delta;

	slen = 0;
	while (s && s[slen])
		slen++;
	delta = (slen - (start));
	if (delta > 0 && delta <= slen)
		slen = len;
	else if (delta > 0 && delta > slen)
		slen = delta;
	else
		slen = 0;
	if (!(str = (char *)malloc(sizeof(char) * (slen + 1))))
		return (NULL);
	str[slen] = 0;
	while (--slen >= 0)
		str[slen] = s[start + slen];
	return (str);
}
