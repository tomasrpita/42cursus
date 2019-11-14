/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomasrpita <tomasrpita@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 18:16:47 by tpita-de          #+#    #+#             */
/*   Updated: 2019/11/14 06:44:26 by tomasrpita       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



char	*ft_strrchr(const char *s, int c)
{
	char *pos;
    
    pos = (0);
	while (*s)
	{
		if ((unsigned char)*s == (unsigned char)c)
            pos = (char *)s;
        s++;
	}
	if (pos)
        return (pos);
    if (c == '\0')
		return ((char*)s);
	return (NULL);
}
