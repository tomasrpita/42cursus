/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomasrpita <tomasrpita@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 07:10:38 by tomasrpita        #+#    #+#             */
/*   Updated: 2019/11/12 07:13:34 by tomasrpita       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
#define LIBFT_H


#include <stdlib.h>

void *memset(void *s, int c, size_t n);
void bzero(void *s, size_t n);
void *memcpy(void *dest, const void *src, size_t n);
void *memmove(void *dest, const void *src, size_t n);
void *memchr(const void *s, int c, size_t n);
int memcmp(const void *s1, const void *s2, size_t n);
size_t strlen(const char *s);
int isalpha(int c);
int isdigit(int c);
int isalnum(int c);
int isascii(int c);
int isprint(int c);

#endif