/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pid.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 22:46:00 by mcaro-ro          #+#    #+#             */
/*   Updated: 2024/12/18 20:35:08 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_infile_pid(t_file *infile, int pipe_fd[2], char **argv, char **envp)
{
	ft_init_file(infile, ERR_INFILE, O_RDONLY, 0);
	ft_open_file(infile, argv[1]);
	if (dup2(infile->file, STDIN_FILENO) == -1)
		ft_handle_error(ERR_DUP2);
	if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
		ft_handle_error(ERR_DUP2);
	ft_close_all(*infile, pipe_fd);
	ft_execute_cmd(argv[2], envp);
	return (EXIT_SUCCESS);
}

int	ft_outfile_pid(t_file *outfile, int pipe_fd[2], char **argv, char **envp)
{
	ft_init_file(outfile, ERR_OUTFILE, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	ft_open_file(outfile, argv[4]);
	if (dup2(pipe_fd[0], STDIN_FILENO) == -1)
		ft_handle_error(ERR_DUP2);
	if (dup2(outfile->file, STDOUT_FILENO) == -1)
		ft_handle_error(ERR_DUP2);
	ft_close_all(*outfile, pipe_fd);
	ft_execute_cmd(argv[3], envp);
	return (EXIT_SUCCESS);
}

int	ft_wait_n_pids(int n, pid_t pid[2])
{
	int	status;
	int	exit_status;

	while (--n >= 0)
	{
		waitpid(pid[n], &status, 0);
		if (WIFEXITED(status))
		{
			exit_status = WEXITSTATUS(status);
			exit (exit_status);
		}
	}
	return (EXIT_SUCCESS);
}
