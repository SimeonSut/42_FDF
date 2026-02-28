/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssutarmi <ssutarmi@student_42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:38:18 by ssutarmi          #+#    #+#             */
/*   Updated: 2026/02/28 17:33:23 by ssutarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	pixel_put(t_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

int	hexptr_int(char *color)
{
	int		i;
	int		color_int;

	i = 0;
	color_int = 0;
	if (!color)
		return (16777215);
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
	x_displace[X] = (int)floor(child->x_unit_v[X] * child->x_gap * index);
	x_displace[Y] = (int)floor(child->x_unit_v[Y] * child->y_gap * index);
	y_displace[X] = (int)floor(child->y_unit_v[X] * child->x_gap * head->y);
	y_displace[Y] = (int)floor(child->y_unit_v[Y] * child->y_gap * head->y);
	start[X] = child->origin[X] + x_displace[X] + y_displace[X];
	start[Y] = child->origin[Y] + y_displace[Y] + x_displace[Y] + z;
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
	finish[Y] = child->origin[Y] + y_displace[Y] + x_displace[Y] + z;
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
	finish[Y] = child->origin[Y] + y_displace[Y] + x_displace[Y] + z;
	head->y -= 1;
	return (finish);
}

/*
To decomplicate things: first write a function to turn a single char
representing a hex digit into a value 0-15.
Then the canonical way to parse a hex string representation of an integer,
is to first parse and skip the "0x", then for each hex digit,
multiply the accumulator by 16 (or shift left by 4)
and add the value of the hex digit.
Protip: use unsigned integers where it makes sense,
you may want to use uint32_t for color values.
*/
