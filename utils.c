/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssutarmi <ssutarmi@student_42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 19:54:01 by ssutarmi          #+#    #+#             */
/*   Updated: 2026/02/04 15:31:44 by ssutarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_data	*new_node(void *connection)
{
	t_data	*img;

	img = malloc (sizeof(t_data));
	if (!img)
		return (NULL);
	img->img = mlx_new_image(connection, WIDTH, HEIGHT);
	if (!img->img)
	{
		free(img);
		return (NULL);
	}
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line, &img->endi);
	if (!img->addr)
	{
		free(img);
		return (NULL);
	}
	return (img);
}

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
