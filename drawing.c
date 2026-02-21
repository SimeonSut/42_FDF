/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssutarmi <ssutarmi@student_42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:39:04 by ssutarmi          #+#    #+#             */
/*   Updated: 2026/02/21 20:00:35 by ssutarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_line(t_data *img, int *x, int *y);

void	drawing(t_map *head, t_data *img)
{
	int	x[2] = {842, 1089};
	int	y[2] = {440, 679};

	draw_line(img, x, y);
	head->y += 1;
}

static void	draw_line(t_data *img, int *x, int *y)
{
	int	dx;
	int	dy;
	int	p;

	dx = x[0] - x[1];
	dy = y[0] - y[1];
	p = 2 * dy - dx;
	while (x[0] != x[1])
	{
		pixel_put(img, x[0], y[0], 0x00FFFFFF);
		if (p >= 0)
		{
			y[0] += 1;
			p -= 2 * dx;
		}
		p += 2 * dy;
		x[0] += 1;
	}
}

/*
void	drawing(t_map *y_head, t_data *img, int *space)
{
	int	i;
	int	x_arr[2];
	int	y_arr[2];

	while (y_head)
	{
		i = -1;
		while (y_head->line[++i])
		{
			if (y_head->line[(i + 1)])
			{
				x_arr[0] = (y_head->start[X] + (space[X] * i));
				x_arr[1] = (y_head->start[X] + (space[X] * (i + 1)));
				line_put(img, x_arr, y_head->start[Y], 0x00FFFFFF);
			}
			if (y_head->down && y_head->down->line[i])
			{
				x_arr[0] = y_head->start[X] + (space[X] * i);
				y_arr[0] = y_head->start[Y];
				y_arr[1] = y_head->down->start[Y];
				column_put(img, x_arr[0], y_arr, 0x00FFFFFF);
			}
		}
		y_head = y_head->down;
	}
}*/
