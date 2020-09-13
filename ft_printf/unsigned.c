/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpita-de <tpita-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 12:50:11 by tpita-de          #+#    #+#             */
/*   Updated: 2020/09/10 07:49:51 by tpita-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_padding(int numlen, t_ftpf *f)
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
		if (numlen < f->precision)
			f->width -= (f->precision - numlen);
		while (f->width-- > numlen)
		{
			if (f->fzero && !f->dot)
				f->len += write(1, "0", 1);
			else
				f->len += write(1, " ", 1);
		}
	}
}

static void	print_unsigned_la(intmax_t num, t_ftpf *f)
{
	int numlen;

	numlen = ft_unsigned_numlen(num, 10);
	if (num == 0 && f->dot && !f->precision)
	{
		while (f->width)
		{
			f->len += write(1, " ", 1);
			f->width--;
		}
		return ;
	}
	while (numlen++ < f->precision)
		f->len += write(1, "0", 1);
	f->len += ft_uitoa_base_pf(num, 10, 0);
	while (f->width-- >= numlen)
		f->len += write(1, " ", 1);
}

static void	print_unsigned_ra(uintmax_t num, t_ftpf *f)
{
	int numlen;

	numlen = ft_unsigned_numlen(num, 10);
	if (num == 0 && f->dot && !f->precision)
	{
		while (f->width)
		{
			f->len += write(1, " ", 1);
			f->width--;
		}
		return ;
	}
	print_padding(numlen, f);
	while (numlen++ < f->precision)
		f->len += write(1, "0", 1);
	f->len += ft_uitoa_base_pf(num, 10, 0);
}

void		print_unsigned(t_ftpf *f, va_list ap)
{
	uintmax_t num;

	num = va_arg(ap, unsigned int);
	if (f->fminus)
		print_unsigned_la(num, f);
	else
		print_unsigned_ra(num, f);
}
