/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssutarmi <ssutarmi@student_42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:39:04 by ssutarmi          #+#    #+#             */
/*   Updated: 2026/02/24 20:28:32 by ssutarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	drawing(t_data *img, int start[2], int finish[2]);
static void	orientation_call(t_data *img, int *x, int *y);
static void	draw_line_h(t_data *img, int *x, int *y);
static void	draw_line_v(t_data *img, int *x, int *y);

void	map_to_draw(t_data *img, t_map *head, t_obj *child)
{
	int	start[2];
	int	finish[2];
	int	i;

	start[X] = child->origin[X];
	start[Y] = child->origin[Y];
	while (head)
	{
		i = 0;
		while (head->line[i])
			i++;
		while (i >= 0)
		{
			finish[X] = start[X] - (int)floor(child->x_unit_v[X] * child->scal);
			finish[Y] = start[Y] - (int)floor(child->x_unit_v[Y] * child->scal);
			drawing(img, start, finish);
			start[X] = finish[X];
			start[Y] = finish[Y];
			i--;
		}
		head = head->down;
	}
}

static void	drawing(t_data *img, int start[2], int finish[2])
{
	int	x[2];
	int	y[2];

	x[0] = start[X];
	x[1] = finish[X];
	y[0] = start[Y];
	y[1] = finish[Y];
	orientation_call(img, x, y);
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
