/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssutarmi <ssutarmi@student_42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:39:04 by ssutarmi          #+#    #+#             */
/*   Updated: 2026/02/18 21:05:47 by ssutarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	drawing(t_map *head, t_data *img)
{
	int	i;
	int	x;
	int	y;

	while (head)
	{
		i = 0;
		while (head->line[i])
		{
			x = head->start[X] + head->r_vect[X] * i;
			y = head->start[Y] + head->r_vect[Y] * i;
			pixel_put(img, x, y, 0x00FFFFFF);
			i++;
		}
		head = head->down;
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
