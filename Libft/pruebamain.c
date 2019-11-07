/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ..pruebamain.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpita-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 11:31:45 by tpita-de          #+#    #+#             */
/*   Updated: 2019/11/04 11:49:40 by tpita-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int ft_strlen(char *s);
void *ft_memset(void *str, int c, int n);
void *ft_memccpy(void *dst, const void *src, int c, unsigned int n);

int main()
{
	printf("ft_strlen %d\n^", ft_strlen("Palabra varias"));	

	char str[50];
	memset(str, 1000,7);
   	puts(str);
	char str2[50];
	ft_memset(str2, 1000,7);
	puts(str2);

	/* ft_memccpy */
	char string1[60] = "Taj Mahal is a historic monument in India.";

	char buffer[61];
    char *pdest;
	printf( "Function: _memccpy 42 characters or to character 'c'\n" );
	printf("memccpy \n");
	printf( "Source: %s\n", string1 );
   	pdest = memccpy( buffer, string1, 'c', 42);
	*pdest = '\0';
   	printf( "Result: %s\n", buffer );
   	printf( "Length: %lu characters\n", strlen( buffer ) );

	printf( "Function: _memccpy 42 characters or to character 'c'\n" );
	printf("memccpy \n");
	printf( "Source: %s\n", string1 );
   	
	char buffer2[61];
    char *pdest2;	   
	pdest2 = ft_memccpy( buffer2, string1, 'c', 42);
	*pdest2 = '\0';
   	printf( "Result: %s\n", buffer2 );
   	printf( "Length: %lu characters\n", strlen( buffer2 ) );

}

