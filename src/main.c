/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:08:35 by mcaro-ro          #+#    #+#             */
/*   Updated: 2024/12/17 02:41:08 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int		pipe_fd[2];
	pid_t	pid;
	t_file	infile;
	t_file	outfile;

	if (5 == argc)
	{
		if (ERR == pipe(pipe_fd))
			ft_handle_error(ERR_PIPE);
		pid = fork();
		if (ERR == pid)
			ft_handle_error(ERR_FORK);
		if (CHILD == pid)
			ft_child_pid(&infile, pipe_fd, argv, envp);
		else
		{
			ft_father_pid(&outfile, pipe_fd, argv, envp);
			waitpid(pid, NULL, 0);
		}
	}
	else
		ft_handle_error(USAGE);
	return (EXIT_SUCCESS);
}
