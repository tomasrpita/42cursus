#ifndef FT_PRINTF_H
 # define FT_PRINTF_H

// Recuerda colocar esto donde debe ir
 # include "../libft/libft.h"
 # include <stdarg.h>

 typedef struct		s_ftpf
 {
	 int			idx;
	 int			len;
	//flags
	 int			fzero;
	 int			fminus;

	 int			witdth;
	 int			precision;

 }					t_ftpf;

int					ft_printf(const char *format, ...);

#endif
