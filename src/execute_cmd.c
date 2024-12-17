/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 22:59:40 by mcaro-ro          #+#    #+#             */
/*   Updated: 2024/12/17 03:13:12 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_execute_cmd(char *cmd, char **envp)
{
	char	**args;
	char	*cmd_path;

	if (!cmd || *cmd == '\0')
		ft_handle_error(ERR_CMD_INVALID);

	args = ft_split(cmd, ' ');
	if (!args || !args[0])
		ft_handle_error(ERR_CMD_INVALID);


	cmd_path = ft_find_path(args[0], envp);
	if (!cmd_path)
	{
		ft_free_split(args);
		ft_handle_error(ERR_CMD);
	}
	
	if (-1 == execve(cmd_path, args, envp))
	{
		if (cmd_path != args[0])
			free(cmd_path);
		ft_free_split(args);
		ft_handle_error(ERR_EXEC);
	}
}
