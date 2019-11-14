/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba_strdup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomasrpita <tomasrpita@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 06:08:19 by tomasrpita        #+#    #+#             */
/*   Updated: 2019/11/14 06:29:51 by tomasrpita       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include 'libft.h'
#include <stdlib.h>

 

int main()
{
    char prueba[20] = "Prueba strdup";
    char *st = ft_strdup(prueba);
    printf("%s", *st);
    return (0);
}