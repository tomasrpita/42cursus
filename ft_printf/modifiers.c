/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpita-de <tpita-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 12:57:10 by tpita-de          #+#    #+#             */
/*   Updated: 2020/08/29 13:45:50 by tpita-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	check_flags(const char *format, t_ftpf *f)
{
	while (ft_strchr("0-", format[f->idx]))
	{
		if (format[f->idx] == '0')
			f->fzero = 1;
		if (format[f->idx] == '-')
			f->fminus = 1;
		f->idx++;
	}
	if (f->fzero && f->fminus)
		f->fzero = 0;
}

static void	check_width(const char *format, t_ftpf *f, va_list ap)
{
	if (format[f->idx] == '*')
	{
		f->width = va_arg(ap, int);
		f->fminus = (f->width < 0) ? 1 : f->fminus;
		f->width = (f->width < 0) ? -f->width : f->width;
		while (format[f->idx] == '*')
			f->idx++;
	}
	if (ft_isdigit(format[f->idx]))
	{
		f->width = ft_atoi(&format[f->idx]);
		while (ft_isdigit(format[f->idx]))
		{
			f->idx++;
			if (format[f->idx] == '*')
			{
				f->width = va_arg(ap, int);
				f->width = (f->width < 0) ? -f->width : f->width;
				while (format[f->idx] == '*')
					f->idx++;
			}
		}
	}
}

static void	check_precision(const char *format, t_ftpf *f, va_list ap)
{
	int precision;

	if (format[f->idx] == '.')
	{
		f->idx++;
		f->dot = 1;
		if (ft_isdigit(format[f->idx]))
		{
			f->precision = ft_atoi(&format[f->idx]);
			while (ft_isdigit(format[f->idx]))
				f->idx++;
		}
		else if (format[f->idx] == '*')
		{
			precision = va_arg(ap, int);
			if (precision >= 0)
				f->precision = precision;
			else
				f->dot = 0;
			while (format[f->idx] == '*')
				f->idx++;
		}
	}
}

void		parse_modifiers(const char *format, t_ftpf *f, va_list ap)
{
	if (format[f->idx] == '0' || format[f->idx] == '-')
		check_flags(format, f);
	if (ft_isdigit(format[f->idx]) || format[f->idx] == '*')
		check_width(format, f, ap);
	if (format[f->idx] == '.')
		check_precision(format, f, ap);
}
