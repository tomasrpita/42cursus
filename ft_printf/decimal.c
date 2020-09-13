/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpita-de <tpita-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 13:55:46 by tpita-de          #+#    #+#             */
/*   Updated: 2020/09/11 08:40:20 by tpita-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_decimal_la2(long int num, t_ftpf *f)
{
	if (num == 0 && f->dot && !f->precision)
	{
		while (f->width)
		{
			f->len += write(1, " ", 1);
			f->width--;
		}
		return (1);
	}
	return (0);
}

static int	print_decimal_ra2(long int num, t_ftpf *f, int *neg, int *numlen)
{
	if (num == 0 && f->dot && !f->precision)
	{
		while (f->width)
		{
			f->len += write(1, " ", 1);
			f->width--;
		}
		return (1);
	}
	if (*neg == 1 && f->fzero && !f->dot)
	{
		f->len += write(1, "-", 1);
		*neg = 0;
		numlen--;
	}
	return (0);
}

static void	print_decimal_la(long int num, t_ftpf *f)
{
	int numlen;
	int negative;

	numlen = ft_signed_numlen(num, 10);
	negative = (num < 0) ? 1 : 0;
	num = (num < 0) ? -num : num;
	if (print_decimal_la2(num, f))
		return ;
	if (negative)
	{
		f->len += write(1, "-", 1);
		numlen--;
		f->width--;
	}
	while (numlen++ < f->precision)
		f->len += write(1, "0", 1);
	f->len += ft_itoa_base_pf(num, 10);
	decimal_padding_la(numlen, f);
}

static void	print_decimal_ra(long int num, t_ftpf *f)
{
	int numlen;
	int negative;

	negative = (num < 0) ? 1 : 0;
	numlen = ft_signed_numlen(num, 10);
	num = (num < 0) ? -num : num;
	if (print_decimal_ra2(num, f, &negative, &numlen))
		return ;
	decimal_padding_ra(numlen, negative, f);
	if (negative == 1)
	{
		f->len += write(1, "-", 1);
		numlen--;
	}
	f->precision = f->width > f->precision ? f->width : f->precision;
	while (numlen++ < f->precision)
		f->len += write(1, "0", 1);
	f->len += ft_itoa_base_pf(num, 10);
}

void		print_decimal(t_ftpf *f, va_list ap)
{
	long int	num;

	num = va_arg(ap, int);
	if (f->fminus)
		print_decimal_la(num, f);
	else
		print_decimal_ra(num, f);
}
