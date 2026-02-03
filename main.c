/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssutarmi <ssutarmi@student_42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 13:22:22 by ssutarmi          #+#    #+#             */
/*   Updated: 2026/02/03 16:45:21 by ssutarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(void)
{
	void		*connection;
	void		*window;
	int			i;

	i = 0;
	connection = mlx_init();
	window = mlx_new_window(connection, WIDTH, HEIGHT, "My 1st window");
	while (i < 1000)
	{
		mlx_pixel_put(connection, window, 250 + i, 1750, 0xffff00);
		i++;
	}
	mlx_loop(connection);
	return (0);
}
