/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssutarmi <ssutarmi@student_42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 13:22:22 by ssutarmi          #+#    #+#             */
/*   Updated: 2026/03/07 15:19:55 by ssutarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_map		*head;
	t_wdata		*win;
	t_data		*img;
	t_obj		*child;

	if (checker(argc, argv) == 1)
		return (0);
	head = parsing(argv);
	if (!head)
		return (1);
	win = malloc (sizeof(t_wdata));
	if (!win)
		return (1);
	win->mlx = mlx_init();
	win->win = mlx_new_window(win->mlx, WIDTH, HEIGHT, "test win");
	child = mapping(head);
	if (!child)
		return (1);
	img = new_node(win, head, child);
	if (!img)
		return (1);
	map_to_draw(img, head, child);
	window_handler(img, win);
	return (0);
}
