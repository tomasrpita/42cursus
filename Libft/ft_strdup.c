/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomasrpita <tomasrpita@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 06:08:19 by tomasrpita        #+#    #+#             */
/*   Updated: 2019/11/12 07:08:27 by tomasrpita       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include 'libft.h'

char *ft_strdup(const char *s)
{
    int size;
    char *s2;
    int i;

    size = strlen(s);
    if (!(s2 = (char *)calloc((size + 1), sizeof(char))))
        return (NULL);
    i = 0;
    while (s[i])
    {
        s2[i] = s[i];
        i++;
    }
    /* prueba quitando la siguiente linea con calloc no hace falta*/
    s2[i] = '\0';
    return (s2);
}