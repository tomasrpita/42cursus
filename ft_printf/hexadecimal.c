/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexadecimal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpita-de <tpita-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 12:57:53 by tpita-de          #+#    #+#             */
/*   Updated: 2020/06/28 12:59:02 by tpita-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_hex_la(intmax_t num, t_ftpf *f, char casetp)
{
	int numlen;

	numlen = ft_unsigned_numlen(num, 16);
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
	f->len += ft_uitoa_base_pf(num, 16, casetp);
	while (f->width-- >= numlen)
		f->len += write(1, " ", 1);
}

static void	print_padding(int num, t_ftpf *f)
{
	if (!f->dot)
		while (f->width-- > num)
		{
			if (f->fzero)
				f->len += write(1, "0", 1);
			else
				f->len += write(1, " ", 1);
		}
	else
	{
		if (f->fzero)
			f->width--;
		while (f->width-- > num)
		{
			if (f->fzero)
				f->len += write(1, "0", 1);
			else
				f->len += write(1, " ", 1);
		}
	}
}

static void	print_hex_ra(uintmax_t num, t_ftpf *f, char casetp)
{
	int numlen;

	numlen = ft_unsigned_numlen(num, 16);
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
	f->len += ft_uitoa_base_pf(num, 16, casetp);
}

void		print_hexadecimal(t_ftpf *f, va_list ap, char casetp)
{
	uintmax_t num;

	num = va_arg(ap, unsigned int);
	if (f->fminus)
		print_hex_la(num, f, casetp);
	else
		print_hex_ra(num, f, casetp);
}
