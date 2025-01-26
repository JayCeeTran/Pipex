/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtran <jtran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 16:59:52 by jtran             #+#    #+#             */
/*   Updated: 2024/11/12 14:33:25 by jtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*temp;
	size_t		i;

	i = 0;
	if (start >= ft_strlen(s) || len == 0)
	{
		temp = malloc (1);
		*temp = '\0';
		return (temp);
	}
	if (len > ft_strlen(&s[start]))
	{
		temp = ft_strdup(&s[start]);
		return (temp);
	}
	temp = (char *) malloc((len + 1) * sizeof (char));
	if (!temp)
		return (NULL);
	while (i < len && s[start + i])
	{
		temp[i] = s[start + i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}
