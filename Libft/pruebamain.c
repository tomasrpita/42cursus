/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ..pruebamain.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpita-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 11:31:45 by tpita-de          #+#    #+#             */
/*   Updated: 2019/11/04 11:49:40 by tpita-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int ft_strlen(char *s);
void *ft_memset(void *str, int c, int n);

int main()
{
	printf("ft_strlen %d\n^", ft_strlen("Palabra varias"));	

	char str[50];
	memset(str, 1000,7);
   	puts(str);
	char str2[50];
	ft_memset(str2,'$',7);
	puts(str2);

}

