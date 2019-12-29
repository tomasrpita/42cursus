/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpita-de <tpita-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 17:37:10 by tpita-de          #+#    #+#             */
/*   Updated: 2019/12/22 15:04:30 by tpita-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ************************************************************************** */
/*                                                                            */
/* DESCRIPCION																  */
/* 		borra los datos de la memoria por el tamaño de n comenzando en el *s  */
/*		escribiendo ceros (bytes '\0') en esa area. 						  */
/*												                              */
/* PARAMETROS																  */
/* 		void s: donde se comienza a borrar la memoria  	     				  */
/* 		size_t 	n:  el tamaño de la memoria que sera borrada				  */
/* 												                              */
/* VALOR DE RETORNO 														  */
/* 		nada, void                          								  */
/*												                              */
/* ************************************************************************** */

void	ft_bzero(void *s, size_t n)
{
	char *t_s;

	t_s = s;
	while (n)
	{
		*t_s = '\0';
		t_s++;
		n--;
	}
}
