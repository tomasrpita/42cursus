/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpita-de <tpita-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 19:30:45 by tpita-de          #+#    #+#             */
/*   Updated: 2020/02/09 14:36:19 by tpita-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Para poder usar el printf de prueba */
#include <stdio.h>
#include "libft/libft.h"
#include <stdarg.h>
#include <unistd.h>

int	static ft_putnbr_fd2(int n, int fd)
{
	long int	nbr;
	int	length;

	nbr = n;
	length = 0;
	if (nbr < 0)
	{
		ft_putchar_fd('-', fd);
		nbr = -nbr;
		length += 1;
	}
	if (nbr > 9)
	{
		length += ft_putnbr_fd2(nbr / 10, fd);
		ft_putnbr_fd2(nbr % 10, fd);
	}
	else
		ft_putchar_fd(nbr + '0', fd);
		return(length + 1);
}

/* output hex representation of pointer p, assuming 8-bit bytes */
static int write_ptr(void *p) {
    uintptr_t	x;
    char		buf[2 + sizeof(x) * 2];
    size_t		i;
	size_t		j;

	x = (uintptr_t)p;
    buf[0] = '0';
    buf[1] = 'x';
	i = 0;
	j = 0;
	while(i < sizeof(x) * 2)
	{
        buf[i + 2] = "0123456789abcdef"[(x >> ((sizeof(x) * 2 - 1 - i) * 4)) & 0xf];
		++i;
	}
	/* Esta parafernalia para que no imprima los primero 0 */
	write(1, buf, 2);
	// i = 3;
	i = 0;
	j = -1; // 1 menos los 2 de 0x
	while(i < sizeof(buf))
	{
		if(buf[i + 2] != '0')
			break;
			++j;
		++i;
	}
	while (i < sizeof(buf))
	{
		write(1, &buf[i + 2], 1);
		++i;
	}
	return (i - j);
}

int ft_printf(const char *format, ...)
{
	va_list			valist;
	size_t			lenght;
	int				character;
	char			*string;
	void			*pointer;
	// /* diuXX */
	int				integer;

	lenght = 0;
	va_start(valist, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 's')
			{
				string = va_arg(valist, char *);
				ft_putstr_fd(string, 1);
				lenght += ft_strlen(string);
			}
			else if (*format == 'c')
			{
				character = va_arg(valist, int);
				ft_putchar_fd(character, 1);
				lenght += 1;
			}
			else if (*format == 'p')
			{
				pointer = va_arg(valist, void *);
				lenght += write_ptr(pointer);

			}
			else if (*format == 'd')
			{
				integer = va_arg(valist, int);
				lenght += ft_putnbr_fd2(integer, 1);
			}
			else if (*format == '%')
				ft_putchar_fd(*format, 1);
			format++;
		}
		else
		{
			ft_putchar_fd(*format, 1);
			format++;
			lenght++;
		}

	}
	va_end(valist);
	return ((int)lenght);
}




int main()
{
	int		length;
	int		length2;
	char	*str = "Pedrito";
	void	*p;


	p = &str;
	length = ft_printf("Hola quee tal %s %s %%, caracter: %c,\tpuntero: %p, numero negativo:%d\n", str, "problema", 'T', p, -400);
	length2 = printf("Hola quee tal %s %s %%, caracter: %c,\tpuntero: %p, numero negativo:%d\n", str, "problema", 'T', p, -400);
	printf("length ft_printf: %d\n", length);
	ft_printf("length printf: %d\n", length2);

	printf("\nImprimiendo numeros\n");


	return (length);


}

