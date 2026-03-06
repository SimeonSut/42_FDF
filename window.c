/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssutarmi <ssutarmi@student_42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 21:29:30 by ssutarmi          #+#    #+#             */
/*   Updated: 2026/03/06 21:58:41 by ssutarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	key_handler(int key, t_data *img);
static int	close_window(t_data *img);

void	window_handler(t_data *img, t_wdata *window)
{
	mlx_put_image_to_window(window->mlx, window->win, img->img, 0, 0);
	mlx_hook(window->win, 2, 1L<<0, key_handler, img);
	mlx_hook(window->win, 17, 0, close_window, img);
	mlx_loop(window->mlx);
	destroy_all(img);
	return ;
}

static int	key_handler(int key, t_data *img)
{
	t_data	*new_img;

	new_img = NULL;
	if (img->window)
		if (key == ESC)
			mlx_loop_end(img->window->mlx);
	return (0);
}



static int	close_window(t_data *img)
{
	if (img->window)
		mlx_loop_end(img->window->mlx);
	return (0);
}
