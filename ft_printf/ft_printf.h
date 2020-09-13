/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpita-de <tpita-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 12:36:52 by tpita-de          #+#    #+#             */
/*   Updated: 2020/08/29 13:34:08 by tpita-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdint.h>

typedef struct		s_ftpf
{
	int			idx;
	int			len;
	int			fzero;
	int			fminus;
	int			width;
	int			dot;
	int			precision;
}					t_ftpf;

int					ft_printf(const char *format, ...);
int					ft_signed_numlen(long int num, int base);
int					ft_unsigned_numlen(uintmax_t value, int base);
int					ft_itoa_base_pf(long int value, int base);
int					ft_uitoa_base_pf(uintmax_t value, int base, char x);
void				parse_modifiers(const char *format, t_ftpf *f, va_list ap);
void				print_decimal(t_ftpf *f, va_list ap);
void				print_char(t_ftpf *f, va_list ap);
void				print_string(t_ftpf *f, va_list ap);
void				print_pointer(t_ftpf *f, va_list ap);
void				print_hexadecimal(t_ftpf *f, va_list ap, char type);
void				print_unsigned(t_ftpf *f, va_list ap);
void				print_percent(t_ftpf *f);
void				decimal_padding_la(int numlen, t_ftpf *f);
void				decimal_padding_ra(int numlen, int negative, t_ftpf *f);

#endif
