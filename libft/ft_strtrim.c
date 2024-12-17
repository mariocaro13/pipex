/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 19:23:51 by mcaro-ro          #+#    #+#             */
/*   Updated: 2024/02/27 14:59:20 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_iterate_s1(char const *s1, char const *set)
{
	size_t	i_s1;
	size_t	i_set;
	int		b_same;

	i_s1 = 0;
	b_same = 1;
	while (s1[i_s1] != '\0' && b_same)
	{
		i_set = 0;
		b_same = 0;
		while (set[i_set] != '\0')
		{
			if (s1[i_s1] == set[i_set])
				b_same = 1;
			i_set++;
		}
		i_s1++;
	}
	return (i_s1 - 1);
}

static size_t	ft_get_len(char const *aux, char const *set)
{
	size_t	i_set;
	size_t	i_aux;

	i_set = 0;
	i_aux = ft_strlen(aux) - 1;
	if (i_aux <= 0)
		return (0);
	while (set[i_set] != '\0')
	{
		if (aux[i_aux] == set[i_set])
		{
			i_set = 0;
			i_aux--;
		}
		else
			i_set++;
	}
	return (i_aux + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	char	*aux;
	size_t	len;

	if (!s1 || !set)
		return (NULL);
	aux = (char *)s1 + ft_iterate_s1(s1, set);
	len = ft_get_len(aux, set) + 1;
	str = (char *)ft_calloc(len, sizeof(char));
	if (str)
	{
		ft_strlcpy(str, aux, len);
		return (str);
	}
	return (NULL);
}
