/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpita-de <tpita-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 12:51:22 by tpita-de          #+#    #+#             */
/*   Updated: 2020/08/29 13:48:44 by tpita-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_string_la(char *str, t_ftpf *f)
{
	int strlen;

	if (!str)
		str = "(null)";
	strlen = ft_strlen(str);
	if (f->dot && strlen > 0 && strlen > f->precision)
		strlen = f->precision;
	f->len += write(1, str, strlen);
	while (f->width > strlen)
	{
		f->len += write(1, " ", 1);
		f->width--;
	}
}

static void	print_string_ra(char *str, t_ftpf *f)
{
	int strlen;

	if (!str)
		str = "(null)";
	strlen = ft_strlen(str);
	if (f->dot && strlen > 0 && strlen > f->precision)
		strlen = f->precision;
	while (f->width > strlen)
	{
		if (f->fzero)
			f->len += write(1, "0", 1);
		else
			f->len += write(1, " ", 1);
		f->width--;
	}
	f->len += write(1, str, strlen);
}

void		print_string(t_ftpf *f, va_list ap)
{
	char *str;

	str = va_arg(ap, char *);
	if (f->fminus)
		print_string_la(str, f);
	else
		print_string_ra(str, f);
}
