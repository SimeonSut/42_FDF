/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradians.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssutarmi <ssutarmi@student_42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 01:02:42 by ssutarmi          #+#    #+#             */
/*   Updated: 2026/03/01 01:37:21 by ssutarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	gradiant_populate(t_obj *child);

void	gradiant_find(t_obj *child)
{
	int	i;
	int	j;
	int	color;


	i = 0;
	gradiant_populate(child);
	while (child->map[i])
	{
		j = 0;
		while (child->map[i][j])
		{
			color = child->map[i][j][1];
			if (j > 0 && child->map[i][(j - 1)][1] != color)
				child->map[i][j][LEFT] = child->map[i][(j - 1)][1];
			if (j < child->x_map_len && child->map[i][(j + 1)][1] != color)
				child->map[i][j][RIGHT] = child->map[i][(j + 1)][1];
			if (i > 0 && child->map[(i - 1)][j][1] != color)
				child->map[i][j][UP] = child->map[(i - 1)][j][1];
			if (i < child->y_map_len && child->map[(i + 1)][j][1] != color)
				child->map[i][j][DOWN] = child->map[(i + 1)][j][1];
			j++;
		}
		i++;
	}
}

static void	gradiant_populate(t_obj *child)
{
	int	i;
	int	j;

	i = 0;
	while (child->map[i])
	{
		j = 0;
		while (child->map[i][j])
		{
			child->map[i][j][LEFT] = 0;
			child->map[i][j][RIGHT] = 0;
			child->map[i][j][UP] = 0;
			child->map[i][j][DOWN] = 0;
			j++;
		}
		i++;
	}
}

/*float	*gradient(int *start, int *finish, int start_color, int finish_color)
{
	int		dist_var[2];
	double	draw_dist;
	int		color_var[3];
	float	gradient[3];

	dist_var[X] = start[X] - finish[X];
	if (dist_var[X] < 0)
		dist_var[X] *= -1;
	dist_var[Y] = start[Y] - finish[Y];
	if (dist_var[Y] < 0)
		dist_var[Y] *= -1;
	draw_dist = sqrt((int_pow(dist_var[X], 2) + int_pow(dist_var[Y], 2)));
}*/
