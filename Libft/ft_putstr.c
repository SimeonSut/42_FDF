/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssutarmi <ssutarmi@student_42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 16:09:56 by ssutarmi          #+#    #+#             */
/*   Updated: 2026/02/03 14:15:07 by ssutarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr(int fd, char *str)
{
	int	i;

	if (!str)
		return (ft_putstr(fd, "(null)"), 0);
	i = ft_strlen(str);
	while (*str)
		ft_putchar_fd(*str++, fd);
	return (i);
}
