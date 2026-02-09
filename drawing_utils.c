/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssutarmi <ssutarmi@student_42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:38:18 by ssutarmi          #+#    #+#             */
/*   Updated: 2026/02/09 13:38:23 by ssutarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	pixel_put(t_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	line_put(t_data *img, int *x_arr, int y, int color)
{
	int	x_i;

	x_i = x_arr[0];
	while (x_i != x_arr[1])
		pixel_put(img, x_i++, y, color);
}

void	column_put(t_data *img, int x, int *y_arr, int color)
{
	int	y_i;

	y_i = y_arr[0];
	while (y_i != y_arr[1])
		pixel_put(img, x, y_i++, color);
}
