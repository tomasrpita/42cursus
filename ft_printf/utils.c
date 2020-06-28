#include "ft_printf.h"

int ft_signed_numlen(long int num, int base)
{
	int i;

	i = 0;
	if (num == 0)
		return (1);
	if (num < -9223372036854775807)
		return 20;
	if (num < 0)
	{
		i++;
		num *= -1;
	}
	while (num > 0)
	{
		num /= base;
		i++;
	}
	return (i);
}


int		ft_unsigned_numlen(uintmax_t num, int base)
{
	int		i;

	i = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num /= base;
		i++;
	}
	return (i);
}


int	ft_itoa_base_pf(long int num, int base)
{
	int			len;
	long int	num2;
	char		*radix;
	char		*result;

	len = 1;
	num2 = num;
	if (num < -9223372036854775807)
		return (write(1, "9223372036854775808", 19));
	while (num2 /= base)
		len++;
	if ((result = (char*)malloc(sizeof(char) * (len + 1))) == NULL)
		return (0);
	radix = ft_strdup("0123456789ABCDEF");
	result[len] = '\0';
	while (len-- > 0)
	{
		result[len] = radix[num % base];
		num /= base;
	}
	len = ft_strlen(result);
	write(1, result, len);
	free(radix);
	free(result);
	return (len);
}


int			ft_uitoa_base_pf(uintmax_t num, int base, char x)
{
	int			len;
	uintmax_t	num2;
	char		*radix;
	char		*result;

	len = 1;
	num2 = num;
	while (num2 /= base)
		len++;
	if ((result = (char*)malloc(sizeof(char) * (len + 1))) == NULL)
		return (0);
	radix = (x == 'X') ?
		ft_strdup("0123456789ABCDEF") : ft_strdup("0123456789abcdef");
	result[len] = '\0';
	while (len-- > 0)
	{
		result[len] = radix[num % base];
		num /= base;
	}
	len = ft_strlen(result);
	write(1, result, len);
	free(radix);
	free(result);
	return (len);
}
