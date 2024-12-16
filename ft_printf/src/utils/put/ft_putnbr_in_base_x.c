/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_in_base_x.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:49:31 by mcaro-ro          #+#    #+#             */
/*   Updated: 2024/12/16 17:18:51 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_in_base_x(long nbr, char *base, const int fd, int *count)
{
	long	len;

	if (!base || !fd || !count)
		return ;
	len = ft_strlen(base);
	if (nbr < 0)
	{
		ft_putchar_count('-', fd, count);
		nbr *= -1;
	}
	if (nbr >= len)
		ft_putnbr_in_base_x(nbr / len, base, fd, count);
	ft_putchar_count(base[nbr % len], fd, count);
}
