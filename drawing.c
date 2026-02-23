/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssutarmi <ssutarmi@student_42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:39:04 by ssutarmi          #+#    #+#             */
/*   Updated: 2026/02/23 17:33:08 by ssutarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	orientation_call(t_data *img, int *x, int *y);
static void	draw_line_h(t_data *img, int *x, int *y);
static void	draw_line_v(t_data *img, int *x, int *y);

void	drawing(t_map *head, t_data *img)
{
	int	x[2] = {500, 480};
	int	y[2] = {540, 0};

	orientation_call(img, x, y);
	head = head->down;
}

static void	orientation_call(t_data *img, int *x, int *y)
{
	int	dif_x;
	int	dif_y;

	dif_x = (x[0] - x[1]);
	dif_y = (y[1] - y[0]);
	if (dif_x < 0)
		dif_x *= -1;
	if (dif_y < 0)
		dif_y *= -1;
	if (dif_y > dif_x)
	{
		if (y[0] > y[1])
		{
			y = swap_two_ints(y);
			x = swap_two_ints(x);
		}
		draw_line_v(img, x, y);
		return ;
	}
	if (x[0] > x[1])
	{
		y = swap_two_ints(y);
		x = swap_two_ints(x);
	}
	draw_line_h(img, x, y);
}

static	void	draw_line_h(t_data *img, int *x, int *y)
{
	int	dx;
	int	dy;
	int	p;
	int	dir;

	dx = x[1] - x[0];
	dy = y[1] - y[0];
	dir = 1;
	if (dy < 0)
		dir = -1;
	dy *= dir;
	p = 2 * dy - dx;
	while (x[0] != x[1])
	{
		pixel_put(img, x[0], y[0], 0x00FFFFFF);
		if (p >= 0)
		{
			y[0] += dir;
			p = p - 2 * dx;
		}
		x[0] += 1;
		p = p + 2 * dy;
	}
}

static	void	draw_line_v(t_data *img, int *x, int *y)
{
	int	dx;
	int	dy;
	int	p;
	int	dir;

	dx = x[1] - x[0];
	dy = y[1] - y[0];
	dir = 1;
	if (dx < 0)
		dir = -1;
	dx *= dir;
	p = 2 * dx - dy;
	while (y[0] != y[1])
	{
		pixel_put(img, x[0], y[0], 0x00FFFFFF);
		if (p >= 0)
		{
			x[0] += dir;
			p = p - 2 * dy;
		}
		y[0] += 1;
		p = p + 2 * dx;
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
