/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:08:35 by mcaro-ro          #+#    #+#             */
/*   Updated: 2024/12/16 18:07:34 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv)
{
	if (5 == argc)
	{
		ft_printf("Hola, %i", argv[1]);
	}
	else
		ft_exit_failure();
	return (EXIT_SUCCESS);
}
