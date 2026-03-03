/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssutarmi <ssutarmi@student_42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 13:22:22 by ssutarmi          #+#    #+#             */
/*   Updated: 2026/02/27 14:05:40 by ssutarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


int	main(int argc, char **argv)
{
	t_map	*head;
	t_data	*img;
	t_obj	*child;

	if (argc != 2)
		return (0);
	head = parsing(argv);
	
	if (!head)
		return (1);
	img = new_node();
	child = mapping(head);
	if (!child)
		return (1);
	map_to_draw(img, head, child);
	mlx_put_image_to_window(img->connection, img->window, img->img, 0, 0);
	mlx_loop(img->connection);
	return (0);
}
