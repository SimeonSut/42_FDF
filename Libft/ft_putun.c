/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssutarmi <ssutarmi@student_42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 11:38:49 by ssutarmi          #+#    #+#             */
/*   Updated: 2026/02/03 14:03:01 by ssutarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putposnbr(int fd, unsigned int n)
{
	if (n > 9)
		ft_putposnbr(fd, (n / 10));
	ft_putchar_fd((n % 10) + 48, fd);
}

static int	ft_count(unsigned int nb)
{
	unsigned int	count;
	unsigned int	n;

	count = 0;
	n = nb;
	if (n > 9)
	{
		while (n > 9)
		{
			n /= 10;
			count++;
		}
	}
	if (n >= 0 && n <= 9)
		count++;
	return (count);
}

int	ft_putun(int fd, int nb)
{
	ft_putposnbr(fd, nb);
	return (ft_count(nb));
}
