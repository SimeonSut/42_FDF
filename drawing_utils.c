/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssutarmi <ssutarmi@student_42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:38:18 by ssutarmi          #+#    #+#             */
/*   Updated: 2026/03/01 17:20:17 by ssutarmi         ###   ########.fr       */
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

int	*start_find(t_map *head, t_obj *child, int index)
{
	int	z;
	int	y_displace[2];
	int	x_displace[2];
	int	*start;

	start = malloc(2 * sizeof(int));
	if (!start)
		return (NULL);
	z = child->map[head->y][index][0] * child->z_unit_v[Y];
	x_displace[X] = (int)ceil(child->x_unit_v[X] * child->x_gap * index);
	x_displace[Y] = (int)ceil(child->x_unit_v[Y] * child->y_gap * index);
	y_displace[X] = (int)ceil(child->y_unit_v[X] * child->x_gap * head->y);
	y_displace[Y] = (int)ceil(child->y_unit_v[Y] * child->y_gap * head->y);
	start[X] = child->origin[X] + x_displace[X] + y_displace[X];
	start[Y] = child->origin[Y] + y_displace[Y] + x_displace[Y] + z;
	return (start);
}


int	*finish_find(t_map *head, t_obj *child, int index, int direction)
{
	int	z;
	int	y_displace[2];
	int	x_displace[2];
	int	*finish;

	if (direction == 0)
		index++;
	else
		head->y += 1;
	finish = malloc(2 * sizeof(int));
	if (!finish)
		return (NULL);
	z = child->map[head->y][index][0] * child->z_unit_v[Y];
	x_displace[X] = (int)ceil(child->x_unit_v[X] * child->x_gap * index);
	x_displace[Y] = (int)ceil(child->x_unit_v[Y] * child->y_gap * index);
	y_displace[X] = (int)ceil(child->y_unit_v[X] * child->x_gap * head->y);
	y_displace[Y] = (int)ceil(child->y_unit_v[Y] * child->y_gap * head->y);
	finish[X] = child->origin[X] + y_displace[X] + x_displace[X];
	finish[Y] = child->origin[Y] + y_displace[Y] + x_displace[Y] + z;
	if (direction != 0)
		head->y -= 1;
	return (finish);
}
