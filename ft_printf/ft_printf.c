#include "ft_printf.h"
#include <stdio.h>

static t_ftpf *init_struc(t_ftpf *f)
{
	if (!(f = (t_ftpf*)malloc(sizeof(t_ftpf))))
		return (NULL);
	f->idx = 0;
	f->len = 0;
	return f;
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
	//Comprobar si hace falta esta comprobación
	if (format[0] == '%' && format[1] == '\0')
		;
	else if (!ft_strchr(format, '%'))
		f->len += write(1, format,ft_strlen(format));
	else
		return (0);

	len = f->len;
	free(f);
	va_end(ap);
	return (len);
}

int main()
{
	int 	len;
	len = ft_printf("Hola como estas?\n");
	printf("%d\n", len);
	len = printf("Hola como estas?\n");
	printf("%d\n", len);

	return (0);
}
