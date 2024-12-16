/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:11:49 by mcaro-ro          #+#    #+#             */
/*   Updated: 2024/12/16 17:19:00 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_count(const char *str, const int fd, int *count)
{
	if (!str)
	{
		ft_putstr_count("(null)", fd, count);
		return ;
	}
	while (*str)
	{
		ft_putchar_count(*str, fd, count);
		str++;
	}
}
