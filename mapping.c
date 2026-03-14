/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssutarmi <ssutarmi@student_42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 14:17:43 by ssutarmi          #+#    #+#             */
/*   Updated: 2026/03/14 16:25:22 by ssutarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		setup(t_obj *child);
static void		x_y_setup(t_map *head, t_obj *child);
static void		map_setup(t_map *head, t_obj *child);
static void		z_scaling(t_map *head, t_obj *child);

t_obj	*mapping(t_map *head)
{
	t_obj	*child;

	child = malloc(sizeof(t_obj));
	if (!child)
		return (NULL);
	setup(child);
	x_y_setup(head, child);
	map_setup(head, child);
	z_scaling(head, child);
	gradiant_find(child);
	return (child);
}

static void	setup(t_obj *child)
{
	float	angle;
	float	cos_angle;
	float	sin_angle;

	angle = M_PI / 6;
	child->ref_pi = angle;
	cos_angle = cos(child->ref_pi);
	sin_angle = sin(child->ref_pi);
	child->origin[X] = WIDTH / 100 * 5;
	child->origin[Y] = HEIGHT / 5 * 3;
	child->x_unit_v[X] = cos_angle;
	child->x_unit_v[Y] = sin_angle * -1;
	child->y_unit_v[X] = cos_angle;
	child->y_unit_v[Y] = sin_angle;
	child->z_unit_v[X] = 0;
	child->z_unit_v[Y] = cos(child->ref_pi);
}

static void	x_y_setup(t_map *head, t_obj *child)
{
	int		line_len;
	int		tmp;

	child->z_map_len = 0;
	line_len = -1;
	while (head && head->down)
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
	child->x_map_len = int_abs(line_len);
	child->y_map_len = int_abs(head->y);
	tmp = child->x_map_len + child->y_map_len;
	child->x_gap = WIDTH / (cos(child->ref_pi) * tmp);
	if (child->x_gap == 0)
		child->x_gap = 1;
	child->y_gap = HEIGHT / (sin(child->ref_pi) * tmp);
	if (child->y_gap == 0)
		child->y_gap = 1;
}

static void	map_setup(t_map *head, t_obj *child)
{
	int	i;
	int	j;

	i = -1;
	child->map = malloc((child->y_map_len + 1) * sizeof(int **));
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

static void	z_scaling(t_map *head, t_obj *child)
{
	int	z_max;
	int	z_min;
	int	i;

	z_max = 0;
	z_min = 0;
	while (head && head->down)
	{
		i = -1;
		while (++i < child->x_map_len)
		{
			if (child->map[head->y][i][0] > z_max)
				z_max = child->map[head->y][i][0];
			if (child->map[head->y][i][0] < z_min)
				z_min = child->map[head->y][i][0];
		}
		head = head->down;
	}
	child->z_map_len = int_abs(z_max - z_min);
	if (child->z_map_len == 0)
		child->z_gap = -1;
	else
		child->z_gap = (300.00 / (float)child->z_map_len) * -1;
	if (child->z_gap == 0.000)
		child->z_gap = 1;
}
