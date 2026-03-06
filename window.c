/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssutarmi <ssutarmi@student_42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 01:02:42 by ssutarmi          #+#    #+#             */
/*   Updated: 2026/03/05 18:46:51 by ssutarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	key_handler(int keycode, t_data *img);
static void	translation(int key, t_data *img);
static int	zooming(int button, int x, int y, t_data *img);
static int	close_window(t_data *img);

void	window_handler(t_data *img, t_wdata *window)
{
	mlx_put_image_to_window(window->mlx, window->win, img->img, 0, 0);
	mlx_hook(window->win, 2, 1L<<0, key_handler, img);
	mlx_hook(window->win, 17, 0, close_window, img);
	mlx_mouse_hook(window->win, zooming, img);
	mlx_loop(window->mlx);
	destroy_all(img);
	return ;
}

static int	key_handler(int key, t_data *img)
{
	t_data	*new_img;

	new_img = NULL;
	if (img->window)
	{
		if (key == A_L || key == A_U || key == A_R || key == A_D)
		{
			translation(key, img);
			new_img = new_node(img->window, img->head, img->child);
			if (!new_img)
				return (1);
			map_to_draw(new_img, new_img->head, new_img->child);
			window_handler(new_img, new_img->window);
		}
		else if (key == ESC)
			mlx_loop_end(img->window->mlx);
	}
	if (new_img)
		mlx_put_image_to_window(window->mlx, window->win, new->img->img, 0, 0);
	return (0);
}

static void	translation(int key, t_data *img)
{
	t_data	*new_img;

	if (key == A_L)
		img->child->origin[X] -= 1;
	else if (key == A_U)
		img->child->origin[Y] -= 1;
	else if (key == A_R)
		img->child->origin[X] += 1;
	else if (key == A_D)
		img->child->origin[Y] += 1;
	new_img = new_node(img->window, img->head, img->child);
	if (!new_img)
		return ;
	map_to_draw(new_img, new_img->head, new_img->child);
	window_handler(new_img, new_img->window);
}

static int	zooming(int button, int x, int y, t_data *img)
{
	t_data	*new_img;
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
	new_img = new_node(img->window, img->head, img->child);
	if (!new_img && x && y)
		return (1);
	map_to_draw(new_img, new_img->head, new_img->child);
	window_handler(new_img, new_img->window);
	return (0);
}

static int	close_window(t_data *img)
{
	mlx_loop_end(img->window->mlx);
	return (0);
}
