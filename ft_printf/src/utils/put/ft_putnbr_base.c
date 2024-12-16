/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 20:56:44 by mcaro-ro          #+#    #+#             */
/*   Updated: 2024/12/16 17:18:48 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(unsigned long nbr, char *base, const int fd, int *count)
{
	unsigned long	len;

	if (!base || !fd || !count)
		return ;
	len = ft_strlen(base);
	if (nbr >= len)
		ft_putnbr_base(nbr / len, base, fd, count);
	ft_putchar_count(base[nbr % len], fd, count);
}
