#include "libft/libft.h"
#include <stdio.h>
#include <stdint.h>
#include <unistd.h>

/* output hex representation of pointer p, assuming 8-bit bytes */
void write_ptr(void *p) {
    uintptr_t	x;
    char		buf[2 + sizeof(x) * 2];
    size_t		i;

	x = (uintptr_t)p;
    buf[0] = '0';
    buf[1] = 'x';
	i = 0;
	while(i < sizeof(x) * 2)
	{
        buf[i + 2] = "0123456789abcdef"[(x >> ((sizeof(x) * 2 - 1 - i) * 4)) & 0xf];
		++i;
	}
	/* Esta parafernalia para que no imprima los primero 0 */
	write(1, buf, 2);
	i = 3;
	while(i < sizeof(buf))
	{
		if(buf[i] != '0')
			break;
		++i;
	}
	while (i < sizeof(buf))
	{
		write(1, &buf[i], 1);
		++i;
	}
}



// void print_memory(void *pointer)
// {
// 	const unsigned char* pc;

// 	pc = pointer;
// 	int g;
// 	g = (*(pc) >> 4) & 0xf;
// 	printf("%i", g);

// }

int main ()
{
	char *pointer = "puntero de prueba";

	printf("%p\n", &pointer);
	write_ptr(&pointer);

}
