/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssutarmi <ssutarmi@student_42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 13:22:22 by ssutarmi          #+#    #+#             */
/*   Updated: 2026/03/05 21:36:31 by ssutarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	window_handler(img, window);
	return (0);
}
