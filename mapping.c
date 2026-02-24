/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssutarmi <ssutarmi@student_42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 14:17:43 by ssutarmi          #+#    #+#             */
/*   Updated: 2026/02/24 20:14:43 by ssutarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		unit_vectors_setup(t_obj *child);
static void		x_y_z_gap_setup(t_map *head, t_obj *target);

t_obj	*mapping(t_map *head)
{
	t_obj	*child;

	child = malloc(sizeof(child));
	if (!child)
		return (NULL);
	child->origin[X] = (WIDTH - (WIDTH / 100 * (BUFFER_X / 2))) / 5 * 2;
	child->origin[Y] = HEIGHT - (HEIGHT - (HEIGHT / 100 * (BUFFER_Y / 2)));
	unit_vectors_setup(child);
	x_y_z_gap_setup(head, child);
	return (child);
}

static void	unit_vectors_setup(t_obj *child)
{
	float	pi_six;
	float	cos_pi_six;
	float	sin_pi_six;

	pi_six = M_PI / 6;
	cos_pi_six = cos(pi_six);
	sin_pi_six = sin(pi_six);
	child->x_unit_v[X] = cos_pi_six;
	child->x_unit_v[Y] = sin_pi_six * -1;
	child->y_unit_v[X] = cos_pi_six * -1;
	child->y_unit_v[Y] = sin_pi_six * -1;
	child->z_unit_v[X] = 0;
	child->z_unit_v[Y] = -1;
}

static void	x_y_z_gap_setup(t_map *head, t_obj *child)
{
	int		line_len;
	int		max_height;
	int		tmp;

	max_height = 0;
	while (head->down)
	{
		line_len = 0;
		while (head->line[line_len])
		{
			tmp = ft_atoi(head->line[line_len][0]);
			if (tmp > max_height)
				max_height = tmp;
			line_len++;
		}
		head = head->down;
	}
	child->x_map_len = line_len;
	child->y_map_len = head->y;
	child->scal = line_len + head->y;
	child->z_map_len = max_height;
	child->x_gap = (WIDTH - (WIDTH / 100 * BUFFER_X)) / child->scal;
	child->y_gap = (HEIGHT - (HEIGHT / 100 * BUFFER_Y)) / child->scal;
	child->z_gap = (HEIGHT - (HEIGHT / 100 * BUFFER_Y)) / max_height;
}

/*
printf("child X origin is %d\n", child->origin[X]);
	printf("child Y origin is %d\n", child->origin[Y]);
	printf("child X unit vector x value is %.3f\n", child->x_unit_v[X]);
	printf("child X unit vector y value is %.3f\n", child->x_unit_v[Y]);
	printf("child Y unit vector x value is %.3f\n", child->y_unit_v[X]);
	printf("child Y unit vector y value is %.3f\n", child->y_unit_v[Y]);
	printf("child Z unit vector x value is %.3f\n", child->z_unit_v[X]);
	printf("child Z unit vector y value is %.3f\n", child->z_unit_v[Y]);
	printf("child limit x value is %d\n", child->limit[X]);
	printf("child limit y value is %d\n", child->limit[Y]);
	printf("child x_gap is %d\n", child->x_gap);
	printf("child y_gap is %d\n", child->y_gap);
	printf("child z_gap is %d\n", child->z_gap);
	*/
