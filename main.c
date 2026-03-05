/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssutarmi <ssutarmi@student_42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 13:22:22 by ssutarmi          #+#    #+#             */
/*   Updated: 2026/03/05 16:45:39 by ssutarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_win(int keycode, t_wdata *window, t_data *img);

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
	mlx_key_hook(window->window, close_win, window);
	mlx_loop(window->mlx);
	return (0);
}

int	close_win(int keycode, t_wdata *window, t_data *img)
{
	if (window && keycode == 65307)
    {
		free_t_map(img->head);
		free_t_obj(img->child);
        if (window->mlx && img->img)
            mlx_destroy_image(window->mlx, img->img);
        if (window->mlx && window->window)
            mlx_destroy_window(window->mlx, window->window);
        if (window->mlx)
        {
            mlx_destroy_display(window->mlx);
            free(window->mlx);
        }
        free(img);
    }
	return (0);
}
