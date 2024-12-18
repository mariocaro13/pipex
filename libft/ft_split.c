/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 19:24:04 by mcaro-ro          #+#    #+#             */
/*   Updated: 2024/12/18 02:57:53 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_split(char **arr)
{
	size_t	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

static size_t	ft_strcount(const char *s, char c)
{
	size_t	count;

	count = 1;
	while (*s)
	{
		if (*s != c)
		{
			count++;
			while (*s != '\0' && *s != c)
				s++;
		}
		while (*s != '\0' && *s == c)
			s++;
	}
	return (count);
}

static size_t	ft_lenchr(char const *s, size_t start, char c)
{
	size_t	i;

	i = 0;
	while (s[start + i] != c && s[start + i] != '\0')
		i++;
	return (i);
}

static int	ft_setstrs(char **arr, char const *s, size_t count, char c)
{
	size_t	i_s;
	size_t	i_arr;
	size_t	len_str;

	i_s = 0;
	i_arr = 0;
	while (i_arr < count - 1)
	{
		while (s[i_s] == c)
			i_s++;
		len_str = ft_lenchr(s, i_s, c) + 1;
		arr[i_arr] = (char *)ft_calloc(len_str, sizeof(char));
		if (!arr[i_arr])
		{
			ft_free_split(arr);
			return (0);
		}
		ft_strlcpy(arr[i_arr], s + i_s, len_str);
		i_s = i_s + len_str;
		i_arr++;
	}
	arr[i_arr] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	str_count;

	if (!s)
		return (NULL);
	str_count = ft_strcount(s, c);
	arr = (char **)ft_calloc(str_count, sizeof(char *));
	if (arr)
	{
		if (ft_setstrs(arr, s, str_count, c))
			return (arr);
	}
	free(arr);
	return (NULL);
}
