/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtran <jtran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:19:59 by jtran             #+#    #+#             */
/*   Updated: 2024/11/06 14:10:27 by jtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_count(const char *str, char c)
{
	size_t	count;

	count = 0;
	while (*str)
	{
		while (*str == c && *str)
			str++;
		if (*str)
			count++;
		while (*str != c && *str)
			str++;
	}
	return (count);
}

static char	**free_strs(char **arr, int j)
{
	while (j > 0)
		free (arr[--j]);
	free (arr);
	return (NULL);
}

static char	**dutty(char **arr, int j)
{
	arr[j] = NULL;
	return (arr);
}

char	**ft_split(const char *str, char c)
{
	size_t	words;
	char	**str_arr;
	int		j;
	int		poscount;

	j = 0;
	words = word_count(str, c);
	str_arr = malloc((words + 1) * sizeof(char *));
	if (!str_arr || !str)
		return (NULL);
	while (*str && words-- > 0)
	{
		poscount = 0;
		while (*str == c && *str)
			str++;
		while (*str != c && *str)
		{
			str++;
			poscount++;
		}
		str_arr[j] = ft_substr(str - poscount, 0, poscount);
		if (!str_arr[j++])
			return (free_strs(str_arr, j - 1));
	}
	return (dutty(str_arr, j));
}
