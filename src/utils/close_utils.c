/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 22:37:14 by mcaro-ro          #+#    #+#             */
/*   Updated: 2024/12/18 03:59:37 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_close(t_file file, int pipe_fd[2])
{
	if (file.file >= 0)
		close(file.file);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
}
