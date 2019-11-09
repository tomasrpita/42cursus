/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomasrpita <tomasrpita@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 06:51:18 by tomasrpita        #+#    #+#             */
/*   Updated: 2019/11/09 12:57:51 by tomasrpita       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define NULL 0


void *ft_memset(void *str, int c, unsigned int n)
{
	char *t_str;

	t_str = str;
	while (n)
	{
		*t_str = c;
		t_str++;
		n--;
	}
	return (str);	
}


void ft_bzero(void *s, unsigned int n)
{
	char *t_s;


	t_s = s;
	while (n)
	{
		*t_s = '\0';
		t_s++;
		n--; 
	} 
	
}

void *ft_memccpy(void *dst, const void *src, int c, unsigned int n)
{
	unsigned char *t_dst;
	unsigned char *t_src;
	unsigned int i;

	t_dst = (unsigned char*)dst;
	t_src = (unsigned char *)src;
	i = 0;
	if (dst == NULL || src == NULL)
		return (NULL);
	while (i < n)
	{
		t_dst[i] = t_src[i];
		if (*t_dst == c)
		{
			return ((char *)dst  + i +1);
		}
		i++;
		

	}
	return (NULL);	
	


}

int		ft_strlen(char *s)
{
	int	 i;
	
	i = 0;
	while(s[i])
		i++;
	return (i);
}


int		ft_isalpha(int c)
{
	if ((c > 64 && c < 91) || (c > 96 && c <= 122))
		return (1);
	return (0);
}

int		ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int		ft_isalnum(int c)
{
	if (ft_isdigit(c) || ft_isalpha(c))
		return (1);
	return (0);
}

int		ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

int		ft_isprint(int c)
{
	if (c > 31 && c < 127)
		return (1);
	return (0);
}

int		ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		return (c - 32);
	else
		return (c);		
}

int		ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		return (c + 32);
	else
		return (c);		
}

size_t	ft_strlcpy(char *dst, char const *src, size_t size)
{
	char const	*sptr;
	size_t		slen;

	sptr = src;
	while (*sptr++)
		;
	slen = ((size_t)(sptr - src - 1));
	if (slen < size)
		ft_strncpy(dst, src, slen + 1);
	else if (size != 0)
	{
		ft_strncpy(dst, src, size - 1);
		dst[size - 1] = '\0';
	}
	return (slen);
}

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*result;
	size_t	i;

	i = 0;
	if (nitems == 0 || size == 0)
		return (NULL);
	result = malloc(size * nitems);
	if (result == NULL)
		return (NULL);
	while (i <= nitems)
	{
		((char *)result)[i] = 0;
		i++;
	}
	return (result);
}

char	*ft_strdup(char *src)
{
	char	*new;
	int		i;
	int		size;

	size = 0;
	while (src[size])
		++size;
	if (!(new = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = 0;
	while (src[i])
	{
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char				*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	if (c == 0)
		return ((char *)s + i);
	while (i > 0)
	{
		i--;
		if (s[i] == c)
			return ((char *)s + i);
	}
	return (NULL);
}

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr_dst;
	unsigned char	*ptr_src;

	ptr_dst = (unsigned char*)dst;
	ptr_src = (unsigned char*)src;
	i = 0;
	while (i < n)
	{
		ptr_dst[i] = ptr_src[i];
		if (ptr_dst[i] == (unsigned char)c)
			return ((void*)(dst + i + 1));
		++i;
	}
	return (NULL);
}