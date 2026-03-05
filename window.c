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

static int	close_win(int keycode, t_data *img);
static void	translation(int key, t_data *img);
static void	replace(t_data *img, t_data *tmp_img);
static void	destroy_all(t_data *img);

void	window_handler(t_data *img, t_wdata *window)
{
	mlx_put_image_to_window(window->mlx, window->window, img->img, 0, 0);
	mlx_hook(window->window, 2, 1L<<0, close_win, img);
	mlx_loop(window->mlx);
	destroy_all(img);
	return ;
}

static int	close_win(int key, t_data *img)
{
	ft_printf(STDOUT_FILENO, "keycode is %d\n", key);
	if (img->window)
	{
		if (key == A_L || key == A_U || key == A_R || key == A_D)
		{
			translation(key, img);
			window_handler(img, img->window);
		}
		else if (key == 65307)
			mlx_loop_end(img->window->mlx);
	}
	return (0);
}

static void	translation(int key, t_data *img)
{
	t_data	*tmp;

	if (key == A_L)
		img->child->origin[X] -= 1;
	if (key == A_U)
		img->child->origin[Y] -= 1;
	if (key == A_R)
		img->child->origin[X] += 1;
	if (key == A_D)
		img->child->origin[Y] += 1;
	tmp = malloc (sizeof(t_data));
	if (!tmp)
		return ;
	tmp->img = mlx_new_image(img->window->mlx, WIDTH, HEIGHT);
	if (!tmp->img)
		return (free(tmp));
	tmp->addr = mlx_get_data_addr(tmp->img, &tmp->bpp, &tmp->line, &tmp->endi);
	if (!tmp->addr)
		return (free(tmp));
	if (img->window->mlx && img->img)
		mlx_destroy_image(img->window->mlx, img->img);
	replace(img, tmp);
	return ;
}

static void	replace(t_data *img, t_data *tmp_img)
{
	img->img = tmp_img->img;
	img->addr = tmp_img->addr;
	img->bpp = tmp_img->bpp;
	img->line = tmp_img->line;
	img->endi = tmp_img->endi;
	return ;
}

static void	destroy_all(t_data *img)
{
	if (img->window)
	{
		free_t_obj(img->child);
		free_t_map(img->head);
		if (img->window->mlx && img->img)
			mlx_destroy_image(img->window->mlx, img->img);
		if (img->window->mlx && img->window->window)
			mlx_destroy_window(img->window->mlx, img->window->window);
		if (img->window->mlx)
		{
			mlx_destroy_display(img->window->mlx);
			free(img->window->mlx);
		}
		free(img->window);
		free(img);
	}
}
