/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpita-de <tpita-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 17:43:24 by tpita-de          #+#    #+#             */
/*   Updated: 2019/12/27 18:12:28 by tpita-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ************************************************************************** */
/*                                                                            */
/* DESCRIPCION																  */
/* 		copia n caracteres desde el inicio de src a dst comenzando en el      */
/*		inicio de este. 				                                      */
/*												                              */
/* PARAMETROS																  */
/* 		void *dst: este es un puntero a la matriz de destino donde se   	  */
/*		copiará el contenido, se convertirá en un puntero de tipo void *      */
/*		const void *src: es un puntero a la fuente desde donde se comenzara   */
/*		a copiar.															  */
/* 		size_t 	n:  el tamaño de la memoria que sera copiada				  */
/* 												                              */
/* VALOR DE RETORNO 														  */
/* 		un puntero al destino (dst)           								  */
/*												                              */
/* ************************************************************************** */

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	char			*t_dst;
	char			*t_src;

	if (dst == 0 && src == 0)
		return (NULL);
	t_dst = dst;
	t_src = (char *)src;
	i = 0;
	while (i < n)
	{
		t_dst[i] = t_src[i];
		i++;
	}
	return ((void*)dst);
}
