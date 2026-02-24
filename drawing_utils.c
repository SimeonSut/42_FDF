/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssutarmi <ssutarmi@student_42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:38:18 by ssutarmi          #+#    #+#             */
/*   Updated: 2026/02/24 21:07:28 by ssutarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	pixel_put(t_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

int	*start_find(int *start, t_map *head, t_obj *child, int index)
{
	int	height;
	int	result[2];

	height = ft_atoi(head->line[index]);
	if (head->y == 0 && index == child->x_map_len)
	{
		result[X] = child->origin[X];
		result[Y] = child->origin[Y] + height * (int)child->z_unit_v[Y];
	}
	return (result);
}


int	*finish_find(int *start, t_map *head, t_obj *child, int index)
{
	int	result[2];

	return (result);
}
