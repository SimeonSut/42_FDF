/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssutarmi <ssutarmi@student_42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 14:51:01 by ssutarmi          #+#    #+#             */
/*   Updated: 2026/02/03 14:10:45 by ssutarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check(int fd, char ptr, va_list list, int i)
{
	if (ptr == 'd' || ptr == 'i')
		i += ft_putdec(fd, va_arg(list, int));
	else if (ptr == 'u')
		i += ft_putun(fd, va_arg(list, int));
	else if (ptr == 'x')
		i += ft_puthexa(fd, va_arg(list, unsigned long), "0123456789abcdef");
	else if (ptr == 'X')
		i += ft_puthexa(fd, va_arg(list, unsigned long), "0123456789ABCDEF");
	else if (ptr == 'c')
		i += ft_putchar(fd, va_arg(list, int));
	else if (ptr == 's')
		i += ft_putstr(fd, va_arg(list, char *));
	else if (ptr == 'p')
		i += ft_putptr(fd, va_arg(list, void *));
	else if (ptr == '%')
		i += ft_putchar(fd, 37);
	return (i);
}

int	ft_printf(int fd, const char *ptr, ...)
{
	va_list	list;
	int		i;

	i = 0;
	va_start(list, ptr);
	while (*ptr)
	{
		if (*ptr == '%')
		{
			ptr++;
			i += ft_check(fd, *ptr, list, 0);
		}
		else
		{
			ft_putchar_fd(*ptr, fd);
			i++;
		}
		ptr++;
	}
	va_end(list);
	return (i);
}
