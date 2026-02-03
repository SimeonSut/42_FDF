/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssutarmi <ssutarmi@student_42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 16:34:34 by ssutarmi          #+#    #+#             */
/*   Updated: 2026/02/03 14:11:52 by ssutarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putptr(int fd, void	*s)
{
	int	i;

	if (s == NULL)
		return (ft_putstr(fd, "(nil)"), 0);
	i = ft_putstr(fd, "0x");
	i += ft_puthexap(fd, (unsigned long long)s, "0123456789abcdef");
	return (i);
}
