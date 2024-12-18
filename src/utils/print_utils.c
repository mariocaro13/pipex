/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:25:26 by mcaro-ro          #+#    #+#             */
/*   Updated: 2024/12/18 16:14:20 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_handle_error(const char *message)
{
	perror(message);
	exit(EXIT_FAILURE);
}

void	ft_message(const char *message)
{
	ft_printf(message);
}
