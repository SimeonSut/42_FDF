/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssutarmi <ssutarmi@student_42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 13:22:22 by ssutarmi          #+#    #+#             */
/*   Updated: 2026/03/05 17:26:29 by ssutarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_win(int keycode, t_data *img);

int	main(int argc, char **argv)
{
	t_map		*head;
	t_wdata		*window;
	t_data		*img;
	t_obj		*child;

	if (argc != 2)
		return (0);
	head = parsing(argv);
	if (!head)
		return (1);
	window = malloc (sizeof(t_wdata));
	if (!window)
		return (1);
	window->mlx = mlx_init();
	window->window = mlx_new_window(window->mlx, WIDTH, HEIGHT, "test win");
	child = mapping(head);
	if (!child)
		return (1);
	img = new_node(window, head, child);
	map_to_draw(img, head, child);
	mlx_put_image_to_window(window->mlx, window->window, img->img, 0, 0);
	mlx_key_hook(window->window, close_win, img);
	mlx_loop(window->mlx);
	return (0);
}

int	close_win(int keycode, t_data *img)
{
	if (img->window && keycode == 65307)
	{
		free_t_map(img->head);
		free_t_obj(img->child);
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
	return (0);
}
