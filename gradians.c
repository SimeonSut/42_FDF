/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradians.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssutarmi <ssutarmi@student_42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 01:02:42 by ssutarmi          #+#    #+#             */
/*   Updated: 2026/03/01 16:39:46 by ssutarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	gradiant_find(t_obj *child)
{
	int	i;
	int	j;


	i = 0;
	while (i < child->y_map_len)
	{
		j = 0;
		while (j < child->x_map_len)
		{
			if ((j + 1) < child->x_map_len)
				child->map[i][j][RIGHT] = child->map[i][(j + 1)][1];
			if ((i + 1) < child->y_map_len)
				child->map[i][j][DOWN] = child->map[(i + 1)][j][1];
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
