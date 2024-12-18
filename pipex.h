/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:08:50 by mcaro-ro          #+#    #+#             */
/*   Updated: 2024/12/18 16:14:44 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/** INCLUDES */
# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>

/** DEFINITIONS */
# define EXIT_FAILURE 1
# define EXIT_SUCCESS 0
# define MALLOC_ERROR 1
# define ERR -1

/** MESSAGES */
# define USAGE "Usage: ./pipex <infile> <cmd1> <cmd2> <outfile>\n"
# define ERR_INFILE "Error opening infile\n"
# define ERR_OUTFILE "Error opening/creating outfile\n"
# define ERR_PIPE "Error: Pipe failed\n"
# define ERR_DUP2 "Error: dup2 failed"
# define ERR_FORK "Error: Fork fialed\n"
# define ERR_CMD_INVALID "Error: Invalid command\n"
# define ERR_CMD "Error: Command not found\n"
# define ERR_EXEC "Error: Command execution failed\n"
# define ERR_PATH "Error: Path not found\n"
# define ERR_MALLOC "Error: malloc error\n"

/** PIPES */
# define CHILD 0

/** PATH */
# define PATH "PATH="

/** STRUCTS */
typedef struct s_file
{
	int			file;
	const char	*err_message;
	int			flags;
	int			permissions;
}				t_file;

/** MAIN */
/** main
 * Return:
 *  EXIT_SUCCESS on success, EXIT_FAILURE on error.
 */
int		main(int argc, char **argv, char **envp);

void	ft_init_file(t_file *file, const char *err, int flags, int permissions);

int		ft_open_file(t_file *file, const char *argv);

/** PID */
int		ft_infile_pid(t_file *infile, int pipe_fd[2],
			char **argv, char **envp);

int		ft_outfile_pid(t_file *outfile, int pipe_fd[2],
			char **argv, char **envp);

int		ft_wait_n_pids(int n);

char	*ft_find_path(char *cmd, char **envp);

void	ft_execute_cmd(char *cmd, char **envp);

void	ft_close_pipe_fd(int pipe_fd[2]);

void	ft_close_all(t_file file, int pipe_fd[2]);

void	ft_handle_error(const char *str);

void	ft_message(const char *str);

#endif