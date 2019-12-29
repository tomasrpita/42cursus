/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpita-de <tpita-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 17:24:43 by tpita-de          #+#    #+#             */
/*   Updated: 2019/12/22 14:57:05 by tpita-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ************************************************************************** */
/*                                                                            */
/* DESCRIPCION																  */
/* 		Escribe el valor de c (convertido a unsigned char) la cantidd de 	  */
/*		veces dadas por len en los primeros bytes de  b						  */
/*												                              */
/* PARAMETROS																  */
/* 		void b: donde se va a copiar los caracteres  	     				  */
/* 		int	c:  es un entero con el valor de un caracter					  */
/* 		size_t 	len:  el numero de veces que se copiara c					  */
/* 												                              */
/* VALOR DE RETORNO 														  */
/* 		Retorna b, o sea un puntero void									  */
/*												                              */
/* ************************************************************************** */

void	*ft_memset(void *b, int c, size_t len)
{
	char *t_str;

	t_str = b;
	while (len)
	{
		*t_str = c;
		t_str++;
		len--;
	}
	return (b);
}
