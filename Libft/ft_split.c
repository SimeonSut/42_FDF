/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssutarmi <ssutarmi@student_42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 16:55:59 by ssutarmi          #+#    #+#             */
/*   Updated: 2026/02/05 22:29:42 by ssutarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_separate(char const *str, char c)
{
	unsigned int	count;

	count = 0;
	while (*str && *str != c)
	{
		str++;
		count++;
	}
	return (count);
}

static size_t	ft_splitcount(char const *str, char c)
{
	size_t	count;

	count = 0;
	while (*str)
	{
		if (*str != c)
		{
			count++;
			str += ft_separate(str, c);
		}
		else
			str++;
	}
	return (count);
}

static void	*ft_remove(char **result)
{
	unsigned int	i;

	i = 0;
	while (result[i])
		free(result[i++]);
	free(result);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int				split_count;
	unsigned int	pos;
	char			**result;

	pos = 0;
	if (!s)
		return (NULL);
	split_count = ft_splitcount(s, c);
	result = malloc((split_count + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	result[split_count] = NULL;
	while (*s)
	{
		if (*s != c)
		{
			result[pos] = ft_substr(s, 0, ft_separate(s, c));
			if (!result[pos++])
				return (ft_remove(result));
			s += ft_separate(s, c);
		}
		else
			s++;
	}
	return (result);
}
