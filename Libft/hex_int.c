/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssutarmi <ssutarmi@student_42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 16:52:32 by ssutarmi          #+#    #+#             */
/*   Updated: 2026/02/28 17:17:46 by ssutarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	hex_int(char hexa)
{
	if (ft_isdigit(hexa))
		return ((hexa - 48));
	else if (hexa == 'a' || hexa == 'A')
		return (10);
	else if (hexa == 'b' || hexa == 'B')
		return (11);
	else if (hexa == 'c' || hexa == 'C')
		return (12);
	else if (hexa == 'd' || hexa == 'D')
		return (13);
	else if (hexa == 'e' || hexa == 'E')
		return (14);
	else if (hexa == 'f' || hexa == 'F')
		return (15);
	return (-1);
}
