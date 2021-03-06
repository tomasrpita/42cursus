/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpita-de <tpita-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 13:02:57 by tpita-de          #+#    #+#             */
/*   Updated: 2020/08/29 13:21:27 by tpita-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_char_la(unsigned char c, t_ftpf *f)
{
	f->len += write(1, &c, 1);
	while (f->width > 1)
	{
		f->len += write(1, " ", 1);
		f->width--;
	}
}

static void	print_char_ra(unsigned char c, t_ftpf *f)
{
	while (f->width > 1)
	{
		if (f->fzero)
			f->len += write(1, "0", 1);
		else
			f->len += write(1, " ", 1);
		f->width--;
	}
	f->len += write(1, &c, 1);
}

void		print_char(t_ftpf *f, va_list ap)
{
	unsigned char c;

	c = (unsigned char)va_arg(ap, int);
	if (f->fminus)
		print_char_la(c, f);
	else
		print_char_ra(c, f);
}
