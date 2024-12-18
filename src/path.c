/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 00:23:25 by mcaro-ro          #+#    #+#             */
/*   Updated: 2024/12/18 02:51:15 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*ft_get_path_env(char **envp)
{
	int	i;
	int	path_len;

	if (!envp)
		return (NULL);
	i = 0;
	path_len = ft_strlen(PATH);
	while (envp[i])
	{
		if (ft_strncmp(envp[i], PATH, path_len) == 0)
			return (envp[i] + path_len);
		i++;
	}
	return (NULL);
}

static char	*ft_join_path_cmd(char *path, char *cmd)
{
	char	*full_path;
	char	*temp;

	temp = ft_strjoin(path, "/");
	if (!temp)
	{
		ft_handle_error(ERR_PATH);
		return (NULL);
	}
	full_path = ft_strjoin(temp, cmd);
	if (!full_path)
	{
		ft_handle_error(ERR_PATH);
		return (NULL);
	}
	free(temp);
	return (full_path);
}

char	*ft_search_paths(char **paths, char *cmd)
{
	char	*full_path;
	int		i;

	if (!paths || !cmd || *cmd == '\0')
		return (NULL);
	i = 0;
	while (paths[i])
	{
		full_path = ft_join_path_cmd(paths[i], cmd);
		if (!full_path)
			return (NULL);
		if (0 == access(full_path, X_OK))
			return (full_path);
		free(full_path);
		i++;
	}
	return (NULL);
}

char	*ft_find_path(char *cmd, char **envp)
{
	char	*path_env;
	char	**paths;
	char	*full_path;

	if (!cmd || *cmd == '\0')
	{
		ft_handle_error(ERR_PATH);
		return (NULL);
	}
	path_env = ft_get_path_env(envp);
	if (!path_env)
		return (NULL);
	paths = ft_split(path_env, ':');
	if (!paths)
		return (NULL);
	full_path = ft_search_paths(paths, cmd);
	ft_free_split(paths);
	return (full_path);
}
