/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssutarmi <ssutarmi@student_42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 19:54:01 by ssutarmi          #+#    #+#             */
/*   Updated: 2026/03/01 01:03:19 by ssutarmi         ###   ########.fr       */
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


int	*swap_two_ints(int	*arr)
{
	int	tmp;

	tmp = arr[0];
	arr[0] = arr[1];
	arr[1] = tmp;
	return (arr);
}
