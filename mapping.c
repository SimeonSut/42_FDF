/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssutarmi <ssutarmi@student_42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 14:17:43 by ssutarmi          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/03/07 16:40:13 by ssutarmi         ###   ########.fr       */
=======
/*   Updated: 2026/03/04 14:08:21 by ssutarmi         ###   ########.fr       */
>>>>>>> main
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
	float	pi_six;
	float	cos_pi_six;
	float	sin_pi_six;

	pi_six = M_PI / 6;
	cos_pi_six = cos(pi_six);
	sin_pi_six = sin(pi_six);
	child->origin[X] = WIDTH / 100 * 5;
	child->origin[Y] = HEIGHT / 5 * 3;
	child->ref_pi = pi_six;
	child->x_unit_v[X] = cos_pi_six;
	child->x_unit_v[Y] = sin_pi_six * -1;
	child->y_unit_v[X] = cos_pi_six;
	child->y_unit_v[Y] = sin_pi_six;
}

static void	x_y_setup(t_map *head, t_obj *child)
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
	child->x_gap = WIDTH / (int)(cos(child->ref_pi) * (float)tmp);
	if (child->x_gap == 0)
		child->x_gap = 1;
	child->y_gap = HEIGHT / (int)(sin(child->ref_pi) * (float)tmp);
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
	int	z_range;
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
	z_range = int_abs(z_max - z_min);
	if (z_range == 0)
		z_range = 150;
	if (child->x_map_len <= 50 || child->x_map_len <= 50)
		z_range *= 1.5;
	child->z_unit_v[Y] = (150.00 / (float)z_range) * -1;
}
