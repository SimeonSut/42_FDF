/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssutarmi <ssutarmi@student_42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:38:18 by ssutarmi          #+#    #+#             */
/*   Updated: 2026/03/09 16:35:32 by ssutarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	pixel_put(t_data *img, int x, int y, int color)
{
	char	*dst;

	if (x > WIDTH || x < 0 || y > HEIGHT || y < 0)
		return ;
	dst = img->addr + (y * img->line + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

int	color_char_int(char *color)
{
	int		white;
	int		i;
	int		color_int;

	white = 16777215;
	if (!color)
		return (white);
	i = 0;
	color_int = 0;
	color += 2;
	while (color[i])
	{
		color_int *= 16;
		color_int += hex_int(color[i]);
		i++;
	}
	return (color_int);
}

int	*start_find(t_map *head, t_obj *child, int i)
{
	int	x_vector[2];
	int	y_vector[2];
	int	z_vector[2];
	int	*start;

	start = malloc(2 * sizeof(int));
	if (!start)
		return (NULL);
	x_vector[X] = child->x_unit_v[X] * child->x_gap * i;
	x_vector[Y] = child->x_unit_v[Y] * child->y_gap * i;
	y_vector[X] = child->y_unit_v[X] * child->x_gap * head->y;
	y_vector[Y] = child->y_unit_v[Y] * child->y_gap * head->y;
	z_vector[X] = child->z_unit_v[X] * child->z_gap * child->map[head->y][i][0];
	z_vector[Y] = child->z_unit_v[Y] * child->z_gap * child->map[head->y][i][0];
	start[X] = child->origin[X] + x_vector[X] + y_vector[X] + z_vector[X];
	start[Y] = child->origin[Y] + y_vector[Y] + x_vector[Y] + z_vector[Y];
	return (start);
}

int	*finish_find(t_map *head, t_obj *child, int i, int direction)
{
	int	x_vector[2];
	int	y_vector[2];
	int	z_vector[2];
	int	*finish;

	if (direction == 0)
		i++;
	else
		head->y += 1;
	finish = malloc(2 * sizeof(int));
	if (!finish)
		return (NULL);
	x_vector[X] = child->x_unit_v[X] * child->x_gap * i;
	x_vector[Y] = child->x_unit_v[Y] * child->y_gap * i;
	y_vector[X] = child->y_unit_v[X] * child->x_gap * head->y;
	y_vector[Y] = child->y_unit_v[Y] * child->y_gap * head->y;
	z_vector[X] = child->z_unit_v[X] * child->z_gap * child->map[head->y][i][0];
	z_vector[Y] = child->z_unit_v[Y] * child->z_gap * child->map[head->y][i][0];
	finish[X] = child->origin[X] + y_vector[X] + x_vector[X] + z_vector[X];
	finish[Y] = child->origin[Y] + y_vector[Y] + x_vector[Y] + z_vector[Y];
	if (direction != 0)
		head->y -= 1;
	return (finish);
}
