#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

int mini_printf(char *str, ...)
{
	va_list	valist;
	int		lenght;
	char	*string;

	lenght = 0;
	va_start(valist, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str == 's')
			{
				string = va_arg(valist, char *);
				write(1, string, strlen(string));
				lenght += strlen(string);
			}
			str++;
		}
		else
		{
			write(1, str, 1);
			str++;
			lenght++;
		}

	}
	return lenght;
}

int main()
{
	int		length;
	char	*str = "Pedrito";

	length = mini_printf("Hola quee tal %s %s, que hubo", str, "Lopez");
	return (length);
}
