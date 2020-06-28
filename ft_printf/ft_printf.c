#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

static t_ftpf *init_struc(t_ftpf *f)
{
	if (!(f = (t_ftpf*)malloc(sizeof(t_ftpf))))
		return (NULL);
	*f = (t_ftpf){ .idx = 0, .len = 0,};
	return (f);
}

static void reset_struct(t_ftpf *f )
{
	f->fzero = 0;
	f->fminus = 0;
	f->width = 0;
	f->dot = 0;
	f->precision = 0;
}


static void print_type(const char *format, t_ftpf *f, va_list ap)
{
	// "cspdiuxX%"
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



static void process_format(const char *format, t_ftpf *f, va_list ap)
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

int ft_printf(const char *format, ...)
{
	int 		len;
	t_ftpf		*f;
	va_list		ap;

	f = NULL;
	if(!(f = init_struc(f)))
		return (-1);
	va_start(ap, format);
	if (format[0] == '%' && format[1] == '\0')
	 	return (-1);
	else if (!ft_strchr(format, '%'))
		f->len += write(1, format,ft_strlen(format));
	else
		process_format(format, f, ap);
	len = f->len;
	free(f);
	va_end(ap);
	return (len);
}

// int main()
// {
// 	int 	len;
// 	// int		entero;
// 	// len = ft_printf("Hola como estas?\n");
// 	// printf("%d\n", len);
// 	// len = printf("Hola como estas?\n");
// 	// printf("%d\n", len);

// 	// printf("Decimales: %%i %%d\n");
// 	// len = ft_printf("ft_printf: %0*4iT\n", 42);
// 	// printf("%d\n", len);
// 	// len = printf("printf:    %04*iT\n", 42);
// 	// printf("%d\n", len);

// 	// printf("Char: %%c\n");
// 	// len = ft_printf("ft_printf: %0.*d %.2c \n", 42, 'A');
// 	// printf("%d\n", len);
// 	// len = printf("printf:    %0.*d %.2c \n", 42, 'A');
// 	// printf("%d\n", len);

// 	// printf("String: %%s\n");
// 	// len = ft_printf("%s", "This is ");
// 	// printf("%d\n", len);
// 	// len = printf("%s", "This is ");
// 	// printf("%d\n", len);

// 	// len = ft_printf("%.*s\n", 9, "ft_printf and ft_dprintf");
// 	// printf("%d\n", len);
// 	// len = printf("%.*s\n", 9, "ft_printf and ft_dprintf");
// 	// printf("%d\n", len);

// 	// printf("Decimales: %%i %%d\n");
// 	// len = ft_printf("ft_printf: %0*.2iT\n", 42);
// 	// printf("%d\n", len);
// 	// len = printf("printf:    %0*.2iT\n", 42);
// 	// printf("%d\n", len);

// 	// ft_printf("%05d\n", 42);


// 	// printf("Puntero: %%p\n");
// 	// len = ft_printf("ft_printf: %p\n", &len);
// 	// printf("%d\n", len);
// 	// len = printf("printf:    %p\n", &len);
// 	// printf("%d\n", len);

// 	// entero = 42;
// 	// printf("Puntero: %%p\n");
// 	// len = ft_printf("%*p\n", 1, &entero);
// 	// printf("%d\n", len);
// 	// len = printf("%*p\n", 1, &entero);
// 	// printf("%d\n", len);

// 	// printf("Puntero: %%p\n");
// 	// len = ft_printf("%x\n", 16417188);
// 	// printf("%d\n", len);
// 	// len = printf("%x\n", 16417188);
// 	// printf("%d\n", len);

// 	// printf("unsigned: %%u\n");
// 	// len = ft_printf("%u\n", UINT_MAX);
// 	// printf("%d\n", len);
// 	// len = printf("%u\n", UINT_MAX);
// 	// printf("%d\n", len);

// 	// printf("unsigned: %%u\n");
// 	// len = ft_printf("%u\n", -42);
// 	// printf("%d\n", len);
// 	// len = printf("%u\n", -42);
// 	// printf("%d\n", len);

// 	// printf("sing: %%\n");
// 	// len = ft_printf("%");
// 	// printf("%d\n", len);
// 	// len = printf("%");
// 	// printf("%d\n", len);

// 	return (0);
// }

