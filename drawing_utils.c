/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssutarmi <ssutarmi@student_42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:38:18 by ssutarmi          #+#    #+#             */
/*   Updated: 2026/02/27 23:22:53 by ssutarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	pixel_put(t_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

int	hexint(char *color, char *hexa)
{
	int		i;
	int		len;
	int		j;
	int		color_int;

	i = 0;
	color_int = 0;
	if (!color)
		return (16777215);
	hexa++;
	hexa++;
	while (color[i])
		i++;
	i--;
	len = i;
	while (i >= 0)
	{
		j = 0;
		while (color[i] != hexa[j])
			j++;
		color_int += j * int_pow(16, int_abs((i - len)));
		i--;
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
	x_displace[X] = (int)floor(child->x_unit_v[X] * child->x_gap * index);
	x_displace[Y] = (int)floor(child->x_unit_v[Y] * child->y_gap * index);
	y_displace[X] = (int)floor(child->y_unit_v[X] * child->x_gap * head->y);
	y_displace[Y] = (int)floor(child->y_unit_v[Y] * child->y_gap * head->y);
	start[X] = child->origin[X] + x_displace[X] + y_displace[X];
	start[Y] = child->origin[Y] - y_displace[Y] - x_displace[Y] + z;
	return (start);
}


int	*finish_h_find(t_map *head, t_obj *child, int index)
{
	int	z;
	int	y_displace[2];
	int	x_displace[2];
	int	*finish;

	index++;
	finish = malloc(2 * sizeof(int));
	if (!finish)
		return (NULL);
	z = child->map[head->y][index][0] * child->z_unit_v[Y];
	x_displace[X] = (int)floor(child->x_unit_v[X] * child->x_gap * index);
	x_displace[Y] = (int)floor(child->x_unit_v[Y] * child->y_gap * index);
	y_displace[X] = (int)floor(child->y_unit_v[X] * child->x_gap * head->y);
	y_displace[Y] = (int)floor(child->y_unit_v[Y] * child->y_gap * head->y);
	finish[X] = child->origin[X] + y_displace[X] + x_displace[X];
	finish[Y] = child->origin[Y] - y_displace[Y] - x_displace[Y] + z;
	return (finish);
}

int	*finish_v_find(t_map *head, t_obj *child, int index)
{
	int	z;
	int	y_displace[2];
	int	x_displace[2];
	int	*finish;

	head->y += 1;
	finish = malloc(2 * sizeof(int));
	if (!finish)
		return (NULL);
	z = child->map[head->y][index][0] * child->z_unit_v[Y];
	x_displace[X] = (int)floor(child->x_unit_v[X] * child->x_gap * index);
	x_displace[Y] = (int)floor(child->x_unit_v[Y] * child->y_gap * index);
	y_displace[X] = (int)floor(child->y_unit_v[X] * child->x_gap * head->y);
	y_displace[Y] = (int)floor(child->y_unit_v[Y] * child->y_gap * head->y);
	finish[X] = child->origin[X] + y_displace[X] + x_displace[X];
	finish[Y] = child->origin[Y] - y_displace[Y] - x_displace[Y] + z;
	head->y -= 1;
	return (finish);
}
