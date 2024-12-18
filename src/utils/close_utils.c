/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 22:37:14 by mcaro-ro          #+#    #+#             */
/*   Updated: 2024/12/18 16:01:07 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_close_all(t_file file, int pipe_fd[2])
{
	if (file.file >= 0)
		close(file.file);
	ft_close_pipe_fd(pipe_fd);
}

void	ft_close_pipe_fd(int pipe_fd[2])
{
	close(pipe_fd[0]);
	close(pipe_fd[1]);
}
