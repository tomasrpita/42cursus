/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal_paddings.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpita-de <tpita-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 13:49:55 by tpita-de          #+#    #+#             */
/*   Updated: 2020/06/28 13:58:33 by tpita-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	decimal_padding_la(int numlen, t_ftpf *f)
{
	while (f->width >= numlen)
	{
		f->len += write(1, " ", 1);
		f->width--;
	}
}

void	decimal_padding_ra(int numlen, int negative, t_ftpf *f)
{
	if (!f->dot)
		while (f->width-- > numlen)
		{
			if (f->fzero)
				f->len += write(1, "0", 1);
			else
				f->len += write(1, " ", 1);
		}
	else
	{
		while (f->width-- > f->precision)
		{
			if ((f->fzero && f->width != f->precision) || negative == 1)
				f->len += write(1, "0", 1);
			else
				f->len += write(1, " ", 1);
		}
	}
}
