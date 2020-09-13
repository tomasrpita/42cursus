/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpita-de <tpita-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 13:05:30 by tpita-de          #+#    #+#             */
/*   Updated: 2020/08/29 16:38:30 by tpita-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

static t_ftpf	*init_struc(t_ftpf *f)
{
	if (!(f = (t_ftpf*)malloc(sizeof(t_ftpf))))
		return (NULL);
	*f = (t_ftpf){ .idx = 0, .len = 0};
	return (f);
}

static void		reset_struct(t_ftpf *f)
{
	f->fzero = 0;
	f->fminus = 0;
	f->width = 0;
	f->dot = 0;
	f->precision = 0;
}

static void		print_type(const char *format, t_ftpf *f, va_list ap)
{
	if (format[f->idx] == 'c')
		print_char(f, ap);
	else if (format[f->idx] == 's')
		print_string(f, ap);
	else if (format[f->idx] == 'p')
		print_pointer(f, ap);
	else if (format[f->idx] == 'd' || format[f->idx] == 'i')
		print_decimal(f, ap);
	else if (format[f->idx] == 'u')
		print_unsigned(f, ap);
	else if (format[f->idx] == 'x' || format[f->idx] == 'X')
		print_hexadecimal(f, ap, format[f->idx]);
	else
		print_percent(f);
}

static void		process_format(const char *format, t_ftpf *f, va_list ap)
{
	while (format[f->idx])
	{
		if (format[f->idx] == '%')
		{
			f->idx++;
			if (ft_strchr("-.*0123456789", format[f->idx]))
				parse_modifiers(format, f, ap);
			if (ft_strchr("cspdiuxX%", format[f->idx]))
			{
				print_type(format, f, ap);
				if (f->len == -1)
					return ;
				reset_struct(f);
			}
		}
		else
			f->len += write(1, &format[f->idx], 1);
		f->idx++;
	}
}

int				ft_printf(const char *format, ...)
{
	int		len;
	t_ftpf	*f;
	va_list	ap;

	f = NULL;
	if (!(f = init_struc(f)))
		return (-1);
	va_start(ap, format);
	if (!ft_strchr(format, '%'))
		f->len += write(1, format, ft_strlen(format));
	else
		process_format(format, f, ap);
	len = f->len;
	free(f);
	va_end(ap);
	return (len);
}
