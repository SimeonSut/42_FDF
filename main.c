/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssutarmi <ssutarmi@student_42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 13:22:22 by ssutarmi          #+#    #+#             */
/*   Updated: 2026/03/06 23:19:56 by ssutarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	checker(int argc, char **argv);

int	main(int argc, char **argv)
{
	t_map		*head;
	t_wdata		*window;
	t_data		*img;
	t_obj		*child;

	if (checker(argc, argv) == 1)
		return (0);
	head = parsing(argv);
	if (!head)
		return (1);
	window = malloc (sizeof(t_wdata));
	if (!window)
		return (1);
	window->mlx = mlx_init();
	window->win = mlx_new_window(window->mlx, WIDTH, HEIGHT, "test win");
	child = mapping(head);
	if (!child)
		return (1);
	img = new_node(window, head, child);
	if (!img)
		return (1);
	map_to_draw(img, head, child);
	window_handler(img, window);
	return (0);
}

static int	checker(int argc, char **argv)
{
	char	*fdf;
	int		i;

	fdf = ".fdf";
	i = 0;
	if (argc != 2)
		return (1);
	argv++;
	while (*argv)
	{
		*argv++;
		if (*argv == '.')
		{
			if (ft_strlen(*argv) <= 4)
			{
				if (strncmp(*argv, fdf, ft_strlen(*argv)) == 0)
					return (0);
				else
					return (1);
			}
		}
	}
	return (1);
}
