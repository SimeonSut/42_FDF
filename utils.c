/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssutarmi <ssutarmi@student_42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 19:54:01 by ssutarmi          #+#    #+#             */
/*   Updated: 2026/02/09 20:10:50 by ssutarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_data	*new_node(void)
{
	t_data	*img;

	img = malloc (sizeof(t_data));
	if (!img)
		return (NULL);
	img->connection = mlx_init();
	img->window = mlx_new_window(img->connection, WIDTH, HEIGHT, "2nd window");
	img->img = mlx_new_image(img->connection, WIDTH, HEIGHT);
	if (!img->img)
	{
		free(img);
		return (NULL);
	}
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line, &img->endi);
	if (!img->addr)
	{
		free(img);
		return (NULL);
	}
	return (img);
}

void	space_btw_pts(t_map *y_head, int w_buffer, int y_buffer, int *space)
{
	int		len;
	int		longest;
	t_map	*track;

	longest = 0;
	while (y_head)
	{
		track = y_head;
		len = 0;
		while (y_head->line[len])
			len++;
		if (len > longest)
			longest = len;
		y_head = y_head->down;
	}
	longest--;
	space[X] = ((WIDTH / 100) * (100 - w_buffer)) / longest;
	space[Y] = HEIGHT - ((HEIGHT / 100) * (y_buffer)) / track->y;
	space[Z] = 0;
}
