/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpita-de <tpita-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 12:54:07 by tpita-de          #+#    #+#             */
/*   Updated: 2020/09/10 08:00:49 by tpita-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_pointer_la(intmax_t num, t_ftpf *f)
{
	int numlen;

	numlen = ft_unsigned_numlen(num, 16) + 2;
	f->width = num == 0 && f->dot ? f->width + 1 : f->width;
	f->len += write(1, "0x", 2);
	while (f->precision > (numlen - 2))
	{
		f->len += write(1, "0", 1);
		f->precision--;
	}
	if (num != 0 || !f->dot)
		f->len += ft_uitoa_base_pf(num, 16, 0);
	while (f->width > numlen)
	{
		f->len += write(1, " ", 1);
		f->width--;
	}
}

static void	print_pointer_ra(uintmax_t num, t_ftpf *f)
{
	int numlen;

	numlen = ft_unsigned_numlen(num, 16) + 2;
	numlen = num == 0 && f->dot ? 2 : numlen;
	while (f->width > numlen)
	{
		f->len += write(1, " ", 1);
		f->width--;
	}
	f->len += write(1, "0x", 2);
	if (num == 0 && f->dot && !f->precision)
		return ;
	while ((numlen - 2) < f->precision)
	{
		f->len += write(1, "0", 1);
		numlen++;
	}
	f->len += ft_uitoa_base_pf(num, 16, 0);
}

void		print_pointer(t_ftpf *f, va_list ap)
{
	uintmax_t	num;

	num = (long long)va_arg(ap, void *);
	if (f->fminus)
		print_pointer_la(num, f);
	else
		print_pointer_ra(num, f);
}
