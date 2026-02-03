/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssutarmi <ssutarmi@student_42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 10:14:29 by ssutarmi          #+#    #+#             */
/*   Updated: 2026/02/03 14:02:39 by ssutarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putdec(int fd, int nb)
{
	long	n;
	int		count;

	n = nb;
	count = 0;
	if (n < 0)
	{
		count += ft_putchar(fd, '-');
		n = -n;
	}
	if (n > 9)
		count += ft_putdec(fd, (n / 10));
	count += ft_putchar(fd, ((n % 10) + 48));
	return (count);
}
