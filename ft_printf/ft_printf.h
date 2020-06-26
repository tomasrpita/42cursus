#ifndef FT_PRINTF_H
 # define FT_PRINTF_H

// Recuerda colocar esto donde debe ir
 # include "../libft/libft.h"
 # include <stdarg.h>
 # include <stdint.h> // punteros uintptr_t

 typedef struct		s_ftpf
 {
		int			idx;
		int			len;
		//flags
		int			fzero;
		int			fminus;

		int			width;
		int			dot;
		int			precision;
 }					t_ftpf;

int					ft_printf(const char *format, ...);
void 				print_decimal(t_ftpf *f, va_list ap);
int 				ft_signed_numlen(long int num, int base);
int					ft_unsigned_numlen(uintmax_t value, int base);
int					ft_itoa_base_pf(long int value, int base);
int					ft_uitoa_base_pf(uintmax_t value, int base, char x);
void				print_char(t_ftpf *f, va_list ap);
void				print_string(t_ftpf  *f, va_list ap);
void				print_pointer(t_ftpf  *f, va_list ap);
void 				print_hexadecimal(t_ftpf *f, va_list ap, char type);

#endif
