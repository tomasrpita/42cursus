#include "ft_printf.h"

static void	padding_left_align(int numlen, t_ftpf *f)
{
	while (f->width >= numlen)
	{
		f->len += write(1, " ", 1);
		f->width--;
	}
}


static	void padding_right_align(int numlen, int negative, t_ftpf *f)
{
	if (!f->dot)
		while (f->width-- > numlen)
		{
			if (f->fzero)
				f->len += write(1, "0", 1);
			else
				f->len += write(1, " ", 1);
		}
	else
	{
		while (f->width-- > f->precision)
		{
			if ((f->fzero && f->width != f->precision) || negative == 1)
				f->len += write(1, "0", 1);
			else
				f->len += write(1, " ", 1);
		}
	}
}


static int print_decimal_la2(long int num, t_ftpf *f)
{
	if (num == 0 && f->dot && !f->precision)
	{
		while (f->width)
		{
			f->len += write(1, " ", 1);
			f->width--;
		}
		return(1);
	}
	return(0);
}

static int print_decimal_ra2(long int num, t_ftpf *f, int negative)
{
	if (num == 0 && f->dot && !f->precision)
	{
		while (f->width)
		{
			f->len += write(1, " ", 1);
			f->width--;
		}
		return(1);
	}
	if (negative == 1 && f->fzero)
		f->len += write(1, "-", 1);
	return(0);
}

static void print_decimal_la(long int num, t_ftpf *f)
{
	int numlen;
	int negative;

	numlen = ft_signed_numlen(num, 10);
	negative = (num < 0) ? 1 : 0;
	num = (num < 0) ? -num : num;
	if (print_decimal_la2(num, f))
		return ;
	if (negative)
	{
		f->len += write(1, "-", 1);
		numlen--;
		// donde se inicializo width?
		f->width--;
	}
	while (numlen++ < f->precision)
		f->len += write(1, "0", 1);
	f->len += ft_itoa_base_pf(num, 10);
	padding_left_align(numlen, f);
}

static void print_decimal_ra(long int num, t_ftpf *f)
{
	int numlen;
	int negative;

	numlen = ft_signed_numlen(num, 10);
	negative = (num < 0) ? 1 : 0;
	num = (num < 0) ? -num : num;
	if (print_decimal_ra2(num, f, negative))
		return ;
	padding_right_align(numlen, negative, f);
	if (!f->fzero && negative == 1)
	{
		f->len += write(1, "-", 1);
		numlen--;
	}
	f->precision = (f->width > f->precision) ? f->width : f->precision;
	while (numlen++ < f->precision)
		f->len += write(1, "0", 1);
	f->len += ft_itoa_base_pf(num, 10);
}

void print_decimal(t_ftpf *f, va_list ap)
{

	long int	num;

	num = va_arg(ap, int);
	if (f->fminus)
		print_decimal_la(num, f);
	else
		print_decimal_ra(num, f);
}
