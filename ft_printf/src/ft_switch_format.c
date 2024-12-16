/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_switch_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:11:58 by mcaro-ro          #+#    #+#             */
/*   Updated: 2024/12/16 17:19:08 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_switch_format(va_list args, const unsigned char c, int *count)
{
	if (c == 'c')
		ft_putchar_count(va_arg(args, int), FD, count);
	else if (c == 's')
		ft_putstr_count(va_arg(args, char *), FD, count);
	else if (c == 'p')
		ft_putpointer_count(va_arg(args, unsigned long), FD, count);
	else if (c == 'd')
		ft_putnbr(va_arg(args, int), BASE_DEC, FD, count);
	else if (c == 'i')
		ft_putnbr(va_arg(args, int), BASE_DEC, FD, count);
	else if (c == 'u')
		ft_putnbr_base(va_arg(args, unsigned int), BASE_DEC, FD, count);
	else if (c == 'x')
		ft_putnbr_base(va_arg(args, unsigned int), BASE_HEX_LOWER, FD, count);
	else if (c == 'X')
		ft_putnbr_base(va_arg(args, unsigned int), BASE_HEX_UPPER, FD, count);
	else if (c == '%')
		ft_putchar_count('%', FD, count);
}
