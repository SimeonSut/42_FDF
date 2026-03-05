/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssutarmi <ssutarmi@student_42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 19:54:01 by ssutarmi          #+#    #+#             */
/*   Updated: 2026/03/05 15:37:24 by ssutarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_data	*new_node(t_wdata *window, t_map *head, t_obj *child)
{
	t_data	*img;

	img = malloc (sizeof(t_data));
	if (!img)
		return (NULL);
	img->img = mlx_new_image(window->mlx, WIDTH, HEIGHT);
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
	img->head = head;
	img->child = child;
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
