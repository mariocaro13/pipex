/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:08:35 by mcaro-ro          #+#    #+#             */
/*   Updated: 2024/12/18 04:05:13 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int		pipe_fd[2];
	pid_t	pid[2];
	t_file	infile;
	t_file	outfile;

	if (5 == argc)
	{
		if (ERR == pipe(pipe_fd))
			ft_handle_error(ERR_PIPE);
		pid[0] = fork();
		if (ERR == pid[0])
			ft_handle_error(ERR_FORK);
		if (CHILD == pid[0])
			ft_child_pid(&infile, pipe_fd, argv, envp);
		pid[1] = fork();
		if (ERR == pid[1])
			ft_handle_error(ERR_FORK);
		if (CHILD == pid[1])
			ft_father_pid(&outfile, pipe_fd, argv, envp);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		wait(NULL);
		wait(NULL);
	}
	else
		ft_handle_error(USAGE);
	return (EXIT_SUCCESS);
}
