/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 20:46:06 by mcaro-ro          #+#    #+#             */
/*   Updated: 2024/12/16 22:05:14 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_init_file(t_file *file, const char *err, int flags, int permissions)
{
	file->err_message = err;
	file->flags = flags;
	file->permissions = permissions;
}

int	ft_open_file(t_file *file, const char *argv)
{
	file->file = open(argv, file->flags, file->permissions);
	if (file->file < 0)
		ft_handle_error(file->err_message);
	return (EXIT_SUCCESS);
}
