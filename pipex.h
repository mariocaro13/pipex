/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:08:50 by mcaro-ro          #+#    #+#             */
/*   Updated: 2024/12/16 19:54:10 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/** INCLUDES */
# include "ft_printf/ft_printf.h"
# include <stdlib.h>

/** DEFINITIONS */
# define EXIT_FAILURE 1
# define EXIT_SUCCESS 0
# define MALLOC_ERROR 1
# define USAGE "Usage: ./pipex <infile> <cmd1> <cmd2> <outfile>\n"

/** MAIN */
/** main
 * Return:
 *  EXIT_SUCCESS on success, EXIT_FAILURE on error.
 */
int		main(int argc, char **argv);

void	ft_exit_failure(void);

#endif