/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssutarmi <ssutarmi@student_42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:38:18 by ssutarmi          #+#    #+#             */
/*   Updated: 2026/02/26 17:47:37 by ssutarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	pixel_put(t_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

int	hexachar_to_int(char *color)
{
	int		i;
	int		j;
	char	hexa[16];

	i = 0;
	j = 0;
	hexa = "0123456789ABCDEF";
	while (color[i])
		i++;
	i--;
	while (i >= 0)
	{
		while (color[i] != hexa[j])
			j++;
	}
}

int	*start_find(t_map *head, t_obj *child, int index)
{
	int	z;
	int	y_displacement[2];
	int	x_displacement[2];
	int	*start;

	start = malloc(2 * sizeof(int));
	if (!start)
		return (NULL);
	z = child->map[head->y][index] * child->z_unit_v[Y] * Z_SCALE;
	y_displacement[X] = (int)floor(child->x_unit_v[X] * child->x_gap * head->y);
	x_displacement[X] = (int)floor(child->x_unit_v[X] * child->x_gap * index);
	y_displacement[Y] = (int)floor(child->x_unit_v[Y] * child->y_gap * head->y);
	x_displacement[Y] = (int)floor(child->x_unit_v[Y] * child->y_gap * index);
	start[X] = child->origin[X] - y_displacement[X] + x_displacement[X];
	start[Y] = child->origin[Y] - y_displacement[Y] - x_displacement[Y] + z;
	return (start);
}


int	*finish_h_find(t_map *head, t_obj *child, int index)
{
	int	z;
	int	y_displacement[2];
	int	x_displacement[2];
	int	*finish;

	index++;
	finish = malloc(2 * sizeof(int));
	if (!finish)
		return (NULL);
	z = child->map[head->y][index] * child->z_unit_v[Y] * Z_SCALE;
	y_displacement[X] = (int)floor(child->x_unit_v[X] * child->x_gap * head->y);
	x_displacement[X] = (int)floor(child->x_unit_v[X] * child->x_gap * index);
	y_displacement[Y] = (int)floor(child->x_unit_v[Y] * child->y_gap * head->y);
	x_displacement[Y] = (int)floor(child->x_unit_v[Y] * child->y_gap * index);
	finish[X] = child->origin[X] - y_displacement[X] + x_displacement[X];
	finish[Y] = child->origin[Y] - y_displacement[Y] - x_displacement[Y] + z;
	return (finish);
}

int	*finish_v_find(t_map *head, t_obj *child, int index)
{
	int	z;
	int	y_displacement[2];
	int	x_displacement[2];
	int	*finish;

	head->y += 1;
	finish = malloc(2 * sizeof(int));
	if (!finish)
		return (NULL);
	z = child->map[head->y][index] * child->z_unit_v[Y] * Z_SCALE;
	y_displacement[X] = (int)floor(child->x_unit_v[X] * child->x_gap * head->y);
	x_displacement[X] = (int)floor(child->x_unit_v[X] * child->x_gap * index);
	y_displacement[Y] = (int)floor(child->x_unit_v[Y] * child->y_gap * head->y);
	x_displacement[Y] = (int)floor(child->x_unit_v[Y] * child->y_gap * index);
	finish[X] = child->origin[X] - y_displacement[X] + x_displacement[X];
	finish[Y] = child->origin[Y] - y_displacement[Y] - x_displacement[Y] + z;
	head->y -= 1;
	return (finish);
}
