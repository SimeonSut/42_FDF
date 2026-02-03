/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssutarmi <ssutarmi@student_42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 18:29:04 by ssutarmi          #+#    #+#             */
/*   Updated: 2026/02/03 14:16:17 by ssutarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_puthexa(int fd, unsigned int nbr, char *base)
{
	int		count;
	char	c;

	count = 1;
	if (nbr >= 16)
		count += ft_puthexa(fd, (nbr / 16), base);
	c = base[nbr % 16];
	ft_putchar_fd(c, fd);
	return (count);
}
