/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssutarmi <ssutarmi@student_42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 13:22:22 by ssutarmi          #+#    #+#             */
/*   Updated: 2026/02/07 18:08:49 by ssutarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_map	*map_to_list(int fd);
static t_map	*new_point(char *line, int y);
static char		***input_line(char *line);
//static void		print_map(t_map *y);

int	main(int argc, char **argv)
{
	int		buffer[2];
	t_map	*y_head;
	t_data	img;
	int		space[3];

	if (argc != 2)
		return (0);
	buffer[X] = 30;
	buffer[Y] = 50;
	y_head = parsing(argv, buffer[X], buffer[Y]);
	if (!y_head)
		return (1);
	space = space_between_points(y_head, buffer[X], buffer[Y]);
	img = new_node();
	draw_grid(y_head, img, space);
	mlx_put_image_to_window(connection, window, img->img, 0, 0);
	mlx_loop(connection);
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
