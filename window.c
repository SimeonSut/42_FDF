/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssutarmi <ssutarmi@student_42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 21:29:30 by ssutarmi          #+#    #+#             */
/*   Updated: 2026/03/07 14:35:34 by ssutarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	key_handler(int key, t_data *img);
static int	close_window(t_data *img);

void	window_handler(t_data *img, t_wdata *win)
{
	mlx_put_image_to_window(win->mlx, win->win, img->img, 0, 0);
	mlx_hook(win->win, 2, 1L<<0, key_handler, img);
	mlx_hook(win->win, 17, 0, close_window, img);
	mlx_loop(win->mlx);
	destroy_all(img);
	return ;
}

static int	key_handler(int key, t_data *img)
{
	if (img->win)
	{
		if (key == ESC)
			mlx_loop_end(img->win->mlx);
	}
	return (0);
}

static int	close_window(t_data *img)
{
	if (img->win)
		mlx_loop_end(img->win->mlx);
	return (0);
}
