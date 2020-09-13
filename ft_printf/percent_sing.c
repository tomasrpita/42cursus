/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_sing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpita-de <tpita-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 12:55:54 by tpita-de          #+#    #+#             */
/*   Updated: 2020/08/29 13:45:53 by tpita-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_percent_la(t_ftpf *f)
{
	f->len += write(1, "%", 1);
	while (f->width > 1)
	{
		f->len += write(1, " ", 1);
		f->width--;
	}
}

static void	print_percent_ra(t_ftpf *f)
{
	while (f->width > 1)
	{
		if (f->fzero)
			f->len += write(1, "0", 1);
		else
			f->len += write(1, " ", 1);
		f->width--;
	}
	f->len += write(1, "%", 1);
}

void		print_percent(t_ftpf *f)
{
	if (f->fminus)
		print_percent_la(f);
	else
		print_percent_ra(f);
}
