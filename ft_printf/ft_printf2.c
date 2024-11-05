/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos <pramos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 12:56:32 by pramos            #+#    #+#             */
/*   Updated: 2023/03/13 17:10:07 by pramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_char(char c, int *len)
{
	write(1, &c, 1);
	(*len)++;
}

void	ft_string(char *s, int *len)
{
	if (!s)
	{
		write(1, "(null)", 6);
		(*len) += 6;
		return ;
	}
	while (*s)
	{
		write(1, *&s, 1);
		s++;
		(*len)++;
	}
}

void	ft_void(unsigned long int p, char *base, int *len)
{
	unsigned int	plen;

	plen = ft_strlen_print(base);
	if (p >= plen)
	{
		(*len)++;
		ft_void(p / plen, base, len);
	}
	write(1, &base[p % plen], 1);
}

void	ft_int(int n, int *len)
{
	*len += ft_lenint_print(n);
	ft_putnbr_print(n);
}

void	ft_unsig(unsigned int n, char *base, int *len)
{
	unsigned int	nlen;

	nlen = ft_strlen_print(base);
	if (n >= nlen)
	{
		(*len)++;
		ft_void(n / nlen, base, len);
	}
	write(1, &base[n % nlen], 1);
	(*len)++;
}
