/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssutarmi <ssutarmi@student_42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 14:17:43 by ssutarmi          #+#    #+#             */
/*   Updated: 2026/02/28 17:18:34 by ssutarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		setup(t_obj *child);
static void		x_y_z_setup(t_map *head, t_obj *child);
static void		map_setup(t_map *head, t_obj *child);
static void		rescaling(t_map *head, t_obj *child, int *start, int index);

t_obj	*mapping(t_map *head)
{
	int		i;
	t_obj	*child;
	int		*start;

	child = malloc(sizeof(t_obj));
	if (!child)
		return (NULL);
	setup(child);
	x_y_z_setup(head, child);
	map_setup(head, child);
	while (head && child->map[head->y])
	{
		i = 0;
		while (i < child->x_map_len)
		{
			start = start_find(head, child, i);
			if (start[Y] < 0 || start[Y] > HEIGHT)
				rescaling(head, child, start, i);
			free(start);
			i++;
		}
		head = head->down;
	}
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
	child->origin[Y] = (int)ceil(HEIGHT / 2);
	child->x_unit_v[X] = cos_pi_six;
	child->x_unit_v[Y] = sin_pi_six;
	child->y_unit_v[X] = cos_pi_six * -1;
	child->y_unit_v[Y] = sin_pi_six;
	child->z_unit_v[X] = 0;
	child->z_unit_v[Y] = -3;
}

static void	x_y_z_setup(t_map *head, t_obj *child)
{
	int		line_len;
	int		tmp;

	line_len = 0;
	child->z_map_len = 0;
	while (head->down)
	{
		line_len = 0;
		while (head->line[line_len])
		{
			tmp = ft_atoi(head->line[line_len][0]);
			if (tmp > child->z_map_len)
				child->z_map_len = tmp;
			line_len++;
		}
		head = head->down;
	}
	child->x_map_len = line_len;
	child->y_map_len = head->y;
	child->sca = line_len + head->y;
	child->x_gap = (int)ceil((WIDTH - (WIDTH / 100 * BUFFER_X)) / child->sca);
	child->y_gap = (int)ceil((HEIGHT - (HEIGHT / 100 * BUFFER_Y)) / child->sca);
}

static void	map_setup(t_map *head, t_obj *child)
{
	int	i;
	int	j;

	i = 0;
	child->map = malloc(child->y_map_len * sizeof(int **));
	if (!child->map)
		return ;
	while (i <= child->y_map_len)
	{
		child->map[i] = malloc(child->x_map_len * sizeof(int *));
		if (!child->map[i])
			return ;
		j = 0;
		while (j < child->x_map_len)
		{
			child->map[i][j] = malloc(2 * sizeof(int));
			if (!child->map[i][j])
				return ;
			child->map[i][j][0] = ft_atoi(head->line[j][0]);
			child->map[i][j][1] = hexptr_int(head->line[j][1]);
			j++;
		}
		i++;
		head = head->down;
	}
}

static void	rescaling(t_map *head, t_obj *child, int *start, int index)
{
	float	rescaler;
	int		z;
	int		limit_y;

	z = child->map[head->y][index][0] * child->z_unit_v[Y];
	limit_y = start[Y] - z;
	rescaler = (float)limit_y / (float)z;
	child->x_unit_v[Y] *= rescaler;
	child->y_unit_v[Y] *= rescaler;
	child->z_unit_v[Y] *= rescaler;
}
