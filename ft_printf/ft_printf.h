/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos <pramos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:42:31 by pramos            #+#    #+#             */
/*   Updated: 2023/03/21 16:34:25 by pramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(char const *type, ...);
void	ft_decider(char const *s, va_list args, int *len);

void	ft_char(char c, int *len);
void	ft_string(char *c, int *len);
void	ft_void(unsigned long int p, char *base, int *len);
void	ft_int(int i, int *len);
void	ft_unsig(unsigned int n, char *base, int *len);
void	ft_float(int n, int *len);
void	ft_hexminmay(unsigned int x, char *base, int *len);
void	ft_porcen(int *len);

size_t	ft_strlen_print(const char *s);
void	ft_putnbr_print(int n);
int		ft_lenint_print(int n);

#endif