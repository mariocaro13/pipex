/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:08:50 by mcaro-ro          #+#    #+#             */
/*   Updated: 2024/12/18 18:52:48 by mcaro-ro         ###   ########.fr       */
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
# define ERR_INFILE "Error opening infile"
# define ERR_OUTFILE "Error opening/creating outfile"
# define ERR_PIPE "Error: Pipe failed"
# define ERR_DUP2 "Error: dup2 failed"
# define ERR_FORK "Error: Fork failed"
# define ERR_CMD_INVALID "Error: Invalid command"
# define ERR_CMD "Error: Command not found"
# define ERR_EXEC "Error: Command execution failed"
# define ERR_PATH "Error: Path not found"
# define ERR_MALLOC "Error: malloc error"

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

void	ft_init_file(t_file *file, const char *err, int flags, int permissions);

int		ft_open_file(t_file *file, const char *argv);

int		ft_infile_pid(t_file *infile, int pipe_fd[2],
			char **argv, char **envp);

int		ft_outfile_pid(t_file *outfile, int pipe_fd[2],
			char **argv, char **envp);

int		ft_wait_n_pids(int n, pid_t pid[2]);

char	*ft_find_path(char *cmd, char **envp);

void	ft_execute_cmd(char *cmd, char **envp);

void	ft_close_pipe_fd(int pipe_fd[2]);

void	ft_close_all(t_file file, int pipe_fd[2]);

void	ft_handle_error(const char *str);

void	ft_message(const char *str);

#endif