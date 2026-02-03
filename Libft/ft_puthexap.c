/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssutarmi <ssutarmi@student_42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 15:04:01 by ssutarmi          #+#    #+#             */
/*   Updated: 2026/02/03 13:57:23 by ssutarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_puthexap(int fd, unsigned long long nbr, char *base)
{
	int		count;
	char	c;

	count = 1;
	if (nbr < 0)
	{
		nbr = -nbr;
		ft_putchar_fd('-', fd);
	}
	if (nbr >= 16)
		count += ft_puthexap(fd, nbr / 16, base);
	c = base[nbr % 16];
	ft_putchar_fd(c, fd);
	return (count);
}
