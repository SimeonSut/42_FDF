/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssutarmi <ssutarmi@student_42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:39:04 by ssutarmi          #+#    #+#             */
/*   Updated: 2026/02/28 19:16:41 by ssutarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	drawing(t_data *img, int *start, int *finish, int color);
static void	orientation_call(t_data *img, int *x, int *y, int color);
static void	draw_line_h(t_data *img, int *x, int *y, int color);
static void	draw_line_v(t_data *img, int *x, int *y, int color);

void	map_to_draw(t_data *img, t_map *head, t_obj *child)
{
	int	*start;
	int	*finish;
	int	i;

	while (head)
	{
		i = -1;
		while (head->line[++i])
		{
			start = start_find(head, child, i);
			if (head->down)
			{
				finish = finish_v_find(head, child, i);
				drawing(img, start, finish, child->map[head->y][i][1]);
			}
			if (head->line[i + 1])
			{
				finish = finish_h_find(head, child, i);
				drawing(img, start, finish, child->map[head->y][(i + 1)][1]);
			}
		}
		head = head->down;
	}
}

static void	drawing(t_data *img, int *start, int *finish, int color)
{
	int	x[2];
	int	y[2];

	x[0] = start[X];
	x[1] = finish[X];
	y[0] = start[Y];
	y[1] = finish[Y];
	orientation_call(img, x, y, color);
}

static void	orientation_call(t_data *img, int *x, int *y, int color)
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
		draw_line_v(img, x, y, color);
		return ;
	}
	if (x[0] > x[1])
	{
		y = swap_two_ints(y);
		x = swap_two_ints(x);
	}
	draw_line_h(img, x, y, color);
}

static	void	draw_line_h(t_data *img, int *x, int *y, int color)
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
		pixel_put(img, x[0], y[0], color);
		if (p >= 0)
		{
			y[0] += dir;
			p = p - 2 * dx;
		}
		x[0] += 1;
		p = p + 2 * dy;
	}
}

static	void	draw_line_v(t_data *img, int *x, int *y, int color)
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
		pixel_put(img, x[0], y[0], color);
		if (p >= 0)
		{
			x[0] += dir;
			p = p - 2 * dy;
		}
		y[0] += 1;
		p = p + 2 * dx;
	}
}
