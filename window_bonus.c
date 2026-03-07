/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssutarmi <ssutarmi@student_42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 01:02:42 by ssutarmi          #+#    #+#             */
/*   Updated: 2026/03/05 18:46:51 by ssutarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	key_handler(int keycode, t_data *img);
static int	close_window(t_data *img);

void	window_handler(t_data *img, t_wdata *win)
{
	mlx_put_image_to_window(win->mlx, win->win, img->img, 0, 0);
	mlx_hook(win->win, 2, 1L<<0, key_handler, img);
	mlx_hook(win->win, 17, 0L, close_window, img);
	mlx_mouse_hook(win->win, zooming, img);
	mlx_loop(win->mlx);
	destroy_all(img);
	return ;
}

static int	key_handler(int key, t_data *img)
{
	t_data	*new;

	new = NULL;
	ft_printf(STDOUT_FILENO, "key is %d\n", key);
	if (img->win)
	{
		if (key != ESC)
		{
			if (key == A_L || key == A_U || key == A_R || key == A_D)
				translation(key, img);
			else if (key == Q || key == E)
			new = new_node(img->win, img->head, img->child);
			if (!new)
				return (1);
			map_to_draw(new, new->head, new->child);
			window_handler(new, new->win);
		}
		else if (key == ESC)
			mlx_loop_end(img->win->mlx);
	}
	if (new)
		mlx_put_image_to_window(new->win->mlx, new->win->win, new->img, 0, 0);
	return (0);
}

static int	close_window(t_data *img)
{
	mlx_loop_end(img->win->mlx);
	return (0);
}
