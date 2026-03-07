/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssutarmi <ssutarmi@student_42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 16:30:44 by ssutarmi          #+#    #+#             */
/*   Updated: 2026/03/07 16:46:26 by ssutarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	translation(int key, t_data *img)
{
	t_data	*new;

	if (key == A_L)
		img->child->origin[X] -= 3;
	else if (key == A_U)
		img->child->origin[Y] -= 3;
	else if (key == A_R)
		img->child->origin[X] += 3;
	else if (key == A_D)
		img->child->origin[Y] += 3;
	new = new_node(img->win, img->head, img->child);
	if (!new)
		return ;
	map_to_draw(new, new->head, new->child);
	if (img->win->mlx && img->img)
		mlx_destroy_image(img->win->mlx, img->img);
	free(img);
	window_handler(new, new->win);
}

int	zooming(int button, int x, int y, t_data *img)
{
	t_data	*new;
	float	modifier;

	modifier = 1.00;
	if (button == SCRL_UP)
		modifier = 1.01;
	else if (button == SCRL_DOWN)
		modifier = 0.99;
	img->child->x_unit_v[X] *= modifier;
	img->child->x_unit_v[Y] *= modifier;
	img->child->y_unit_v[X] *= modifier;
	img->child->y_unit_v[Y] *= modifier;
	img->child->z_unit_v[X] *= modifier;
	img->child->z_unit_v[Y] *= modifier;
	new = new_node(img->win, img->head, img->child);
	if (!new && x && y)
		return (1);
	map_to_draw(new, new->head, new->child);
	if (img->win->mlx && img->img)
		mlx_destroy_image(img->win->mlx, img->img);
	free(img);
	window_handler(new, new->win);
	return (0);
}

int	rotation(int button, int x, int y, t_data *img)
{
	return (0);
}
