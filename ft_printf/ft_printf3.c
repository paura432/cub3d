/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos <pramos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:40:13 by pramos            #+#    #+#             */
/*   Updated: 2023/03/13 17:12:14 by pramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_float(int n, int *len)
{
	*len += ft_lenint_print(n);
	ft_putnbr_print(n);
}

void	ft_hexminmay(unsigned int x, char *base, int *len)
{
	unsigned int	xlen;

	xlen = ft_strlen_print(base);
	if (x >= xlen)
	{
		(*len)++;
		ft_void(x / xlen, base, len);
	}
	write(1, &base[x % xlen], 1);
	(*len)++;
}

void	ft_porcen(int *len)
{
	write(1, "%", 1);
	(*len)++;
}
