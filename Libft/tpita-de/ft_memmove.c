/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomasrpita <tomasrpita@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 14:13:23 by tpita-de          #+#    #+#             */
/*   Updated: 2019/11/14 06:44:26 by tomasrpita       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*t_dst;
	const unsigned char	*t_src;

	t_dst = (unsigned char*)dst;
	t_src = (unsigned char*)src;
	i = 0;
	if (t_src < t_dst)
		while (++i <= len)
			t_dst[len - i] = t_src[len - i];
	else
		while (len-- > 0)
			*(t_dst++) = *(t_src++);
	return (dst);
}

