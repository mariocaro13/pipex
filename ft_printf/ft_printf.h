/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:10:52 by mcaro-ro          #+#    #+#             */
/*   Updated: 2024/12/16 16:51:22 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
//# include "libft/libft.h"

# define FD 1
# define BASE_DEC "0123456789"
# define BASE_HEX_LOWER "0123456789abcdef"
# define BASE_HEX_UPPER "0123456789ABCDEF"

int		ft_printf(const char *format, ...);
void	ft_switch_format(va_list args, const unsigned char c, int *count);

/** UTILS */
int		ft_strlen(const char *s);
void	ft_putchar_count(const unsigned char c, const int fd, int *count);
void	ft_putstr_count(const char *str, const int fd, int *count);
void	ft_putpointer_count(unsigned long pointer, const int fd, int *count);
void	ft_putnbr(long nbr, char *base, int fd, int *count);
void	ft_putnbr_base(unsigned long nbr, char *base, int fd, int *count);

#endif
