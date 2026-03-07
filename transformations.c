/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssutarmi <ssutarmi@student_42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 16:30:44 by ssutarmi          #+#    #+#             */
/*   Updated: 2026/03/07 23:32:48 by ssutarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	new_image(t_data *img);
static void	z_rotation_setup(int button, t_data *img);

void	translation(int key, t_data *img)
{
	if (key == A_L)
		img->child->origin[X] -= WIDTH / 100;
	else if (key == A_U)
		img->child->origin[Y] -= HEIGHT / 100;
	else if (key == A_R)
		img->child->origin[X] += WIDTH / 100;
	else if (key == A_D)
		img->child->origin[Y] += HEIGHT / 100;
	new_image(img);
}

int	zooming(int button, int x, int y, t_data *img)
{
	float	modifier;

	modifier = 1.00;
	if (button == SCRL_UP && x)
		modifier = 1.01;
	else if (button == SCRL_DOWN && y)
		modifier = 0.99;
	img->child->x_unit_v[X] *= modifier;
	img->child->x_unit_v[Y] *= modifier;
	img->child->y_unit_v[X] *= modifier;
	img->child->y_unit_v[Y] *= modifier;
	img->child->z_unit_v[X] *= modifier;
	img->child->z_unit_v[Y] *= modifier;
	new_image(img);
	return (0);
}

int	rotation(int button, t_data *img)
{
	float	cos_modifier;
	float	sin_modifier;
	float	teta;

	teta = img->child->ref_pi;
	if (teta > 0 && teta < M_PI)
		cos_modifier = -0.1;
	else
		cos_modifier = 0.1;
	if (teta < ((M_PI / 2) * 3) && teta > (M_PI / 2))
		sin_modifier = -0.1;
	else
		sin_modifier = 0.1;
	if (button == E)
	{
		cos_modifier *= -1;
		sin_modifier *= -1;
	}
	img->child->x_unit_v[X] += cos_modifier;
	img->child->x_unit_v[Y] += sin_modifier;
	img->child->y_unit_v[X] += cos_modifier;
	img->child->y_unit_v[Y] += sin_modifier;
	z_rotation_setup(button, img);
	new_image(img);
	return (0);
}

static void	new_image(t_data *img)
{
	t_data	*new;
	
	new = new_node(img->win, img->head, img->child);
	if (!new)
		return ;
	map_to_draw(new, new->head, new->child);
	if (img->win->mlx && img->img)
		mlx_destroy_image(img->win->mlx, img->img);
	free(img);
	window_handler(new, new->win);
}

static void	z_rotation_setup(int button, t_data *img)
{
	button += 1;
	img->child->x_gap *= 1;
	return ;
}
