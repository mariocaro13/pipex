/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:10:47 by mcaro-ro          #+#    #+#             */
/*   Updated: 2024/12/16 17:19:06 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		count;
	va_list	args;

	if (!str)
		return (-1);
	count = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			ft_switch_format(args, *str, &count);
		}
		else
			ft_putchar_count(*str, FD, &count);
		str++;
	}
	va_end(args);
	return (count);
}
