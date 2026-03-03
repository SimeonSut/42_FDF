/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssutarmi <ssutarmi@student_42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 14:17:43 by ssutarmi          #+#    #+#             */
/*   Updated: 2026/03/01 17:17:13 by ssutarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		setup(t_obj *child);
static void		x_y_z_setup(t_map *head, t_obj *child);
static void		map_setup(t_map *head, t_obj *child);
//static void		rescaling(t_map *head, t_obj *child, int *start, int index);

t_obj	*mapping(t_map *head)
{
	t_obj	*child;

	child = malloc(sizeof(t_obj));
	if (!child)
		return (NULL);
	setup(child);
	x_y_z_setup(head, child);
	map_setup(head, child);
	gradiant_find(child);
	return (child);
}

static void	setup(t_obj *child)
{
	float	pi_six;
	float	cos_pi_six;
	float	sin_pi_six;

	pi_six = M_PI / 6;
	cos_pi_six = cos(pi_six);
	sin_pi_six = sin(pi_six);
	child->origin[X] = (int)ceil(WIDTH / 2);
	child->origin[Y] = (int)ceil(HEIGHT / 4);
	child->x_unit_v[X] = cos_pi_six;
	child->x_unit_v[Y] = sin_pi_six;
	child->y_unit_v[X] = cos_pi_six * -1;
	child->y_unit_v[Y] = sin_pi_six;
	child->z_unit_v[X] = 0;
	child->z_unit_v[Y] = -2;
}

static void	x_y_z_setup(t_map *head, t_obj *child)
{
	int		line_len;
	int		tmp;

	child->z_map_len = 0;
	line_len = -1;
	while (head->down)
	{
		line_len = -1;
		while (head->line[++line_len])
		{
			tmp = ft_atoi(head->line[line_len][0]);
			if (tmp > child->z_map_len)
				child->z_map_len = tmp;
		}
		head = head->down;
	}
	child->x_map_len = line_len;
	child->y_map_len = head->y;
	tmp = line_len + head->y;
	child->x_gap = (WIDTH - (WIDTH / 100 * BUFFER_X)) / tmp;
	if (child->x_gap == 0)
		child->x_gap = 1;
	child->y_gap = (HEIGHT - (HEIGHT / 100 * BUFFER_Y)) / tmp;
	if (child->y_gap == 0)
		child->y_gap = 1;
}

static void	map_setup(t_map *head, t_obj *child)
{
	int	i;
	int	j;

	i = -1;
	child->map = malloc(child->y_map_len * sizeof(int **));
	if (!child->map)
		return ;
	while (++i <= child->y_map_len)
	{
		child->map[i] = malloc(child->x_map_len * sizeof(int *));
		if (!child->map[i])
			return ;
		j = -1;
		while (++j < child->x_map_len)
		{
			child->map[i][j] = malloc(4 * sizeof(int));
			if (!child->map[i][j])
				return ;
			child->map[i][j][0] = ft_atoi(head->line[j][0]);
			child->map[i][j][1] = color_char_int(head->line[j][1]);
		}
		head = head->down;
	}
}

/*static void	rescaling(t_map *head, t_obj *child, int *start, int index)
{
	int		tot_z;
	int		extra;
	float	rescaler;

	tot_z = child->map[head->y][index][0] * child->z_unit_v[Y];
	if (start[Y] < 0)
		extra = (int)ceil(int_abs(start[Y]) / child->z_unit_v[Y]);
	if (start[Y] > HEIGHT)
		extra = (int)((start[Y] - HEIGHT) / child->z_unit_v[Y]);
	rescaler = (float)extra / (float)tot_z;
	child->x_unit_v[Y] = child->x_unit_v[Y] * rescaler;
	child->x_unit_v[X] = child->x_unit_v[X] * rescaler;
	child->y_unit_v[Y] = child->y_unit_v[Y] * rescaler;
	child->y_unit_v[X] = child->y_unit_v[X] * rescaler;
	child->z_unit_v[Y] = child->z_unit_v[Y] * rescaler;
	child->z_unit_v[X] = child->z_unit_v[X] * rescaler;
}*/
