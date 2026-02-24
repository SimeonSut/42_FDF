/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssutarmi <ssutarmi@student_42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 13:22:22 by ssutarmi          #+#    #+#             */
/*   Updated: 2026/02/24 17:56:41 by ssutarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//static void		print_map(t_map *y);

int	main(int argc, char **argv)
{
	t_map	*head;
	t_data	*img;
	t_obj	*child;

	if (argc != 2)
		return (0);
	head = parsing(argv, BUFFER_X, BUFFER_Y);
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

/*
static void	print_map(t_map *y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (y)
	{
		i = 0;
		while (y->line[i])
		{
			ft_printf(STDOUT_FILENO,"%s , %s : ", y->line[i][0], y->line[i][1]);
			i++;
		}
		y = y->down;
		j++;
	}
	ft_printf(STDOUT_FILENO, "\n\nthere is %d y layers registerd\n", j);
}*/
