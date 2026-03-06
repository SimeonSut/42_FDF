/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssutarmi <ssutarmi@student_42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 19:54:01 by ssutarmi          #+#    #+#             */
/*   Updated: 2026/03/06 20:10:16 by ssutarmi         ###   ########.fr       */
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
	img->window = window;
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

void	gradiant_find(t_obj *child)
{
	int	i;
	int	j;


	i = 0;
	while (i < child->y_map_len)
	{
		j = 0;
		while (j < child->x_map_len)
		{
			if ((j + 1) < child->x_map_len)
				child->map[i][j][RIGHT] = child->map[i][(j + 1)][1];
			if ((i + 1) < child->y_map_len)
				child->map[i][j][DOWN] = child->map[(i + 1)][j][1];
			j++;
		}
		i++;
	}
}

void	replace_img(t_data *img)
{
	if (img->window)
	{
		free_t_obj(img->child);
		free_t_map(img->head);
		if (img->window->mlx && img->img)
			mlx_destroy_image(img->window->mlx, img->img);
		if (img->window->mlx && img->window->win)
			mlx_destroy_window(img->window->mlx, img->window->win);
		if (img->window->mlx)
		{
			mlx_destroy_display(img->window->mlx);
			free(img->window->mlx);
		}
		free(img->window);
		free(img);
	}
}


/*float	*gradient(int *start, int *finish, int start_color, int finish_color)
{
	int		dist_var[2];
	double	draw_dist;
	int		color_var[3];
	float	gradient[3];

	dist_var[X] = start[X] - finish[X];
	if (dist_var[X] < 0)
		dist_var[X] *= -1;
	dist_var[Y] = start[Y] - finish[Y];
	if (dist_var[Y] < 0)
		dist_var[Y] *= -1;
	draw_dist = sqrt((int_pow(dist_var[X], 2) + int_pow(dist_var[Y], 2)));
}*/
