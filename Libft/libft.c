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

