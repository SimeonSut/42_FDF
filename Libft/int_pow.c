/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   int_pow.c                                           :+:    :+:           */
/*                                                      +:+                   */
/*   By: ssutarmi <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/02/26 19:50:33 by ssutarmi       #+#    #+#                */
/*   Updated: 2026/02/26 19:50:35 by ssutarmi       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	int_pow(int base, int exponent)
{
	int	result;

	if (exponent == 0)
		return (1);
	result = base;
	while (--exponent > 0)
		result *= base;
	return (result);
}
