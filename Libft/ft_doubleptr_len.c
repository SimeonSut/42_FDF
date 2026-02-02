/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doubleptr_len.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssutarmi <ssutarmi@student_42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 15:51:39 by ssutarmi          #+#    #+#             */
/*   Updated: 2026/01/16 20:59:28 by ssutarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_doubleptr_len(const char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
