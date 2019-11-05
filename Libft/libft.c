void ft_memset(char *str, int c, int n)
{
	while (n > 0)
	{
		*str = c;
		str++;
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

