/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos <pramos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:09:50 by pramos            #+#    #+#             */
/*   Updated: 2023/03/13 17:14:03 by pramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen_print(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putnbr_print(int n)
{
	if (n == -2147483648)
	{
		write(1, "-", 1);
		write(1, "2", 1);
		ft_putnbr_print(147483648);
	}
	else if (n < 0)
	{
		write(1, "-", 1);
		n = n * -1;
		ft_putnbr_print(n);
	}
	else if (n > 9)
	{
		ft_putnbr_print(n / 10);
		ft_putnbr_print(n % 10);
	}
	else
	{
		n += 48;
		write(1, &n, 1);
	}
}

int	ft_lenint_print(int n)
{
	int	i;

	if (n == -2147483648)
	{
		i = 11;
		return (i);
	}
	i = 0;
	if (n == 0)
		i++;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}
