/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssutarmi <ssutarmi@student_42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 19:54:01 by ssutarmi          #+#    #+#             */
/*   Updated: 2026/03/08 16:14:42 by ssutarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_data	*new_node(t_wdata *win, t_map *head, t_obj *child)
{
	t_data	*img;

	img = malloc (sizeof(t_data));
	if (!img)
		return (NULL);
	img->img = mlx_new_image(win->mlx, WIDTH, HEIGHT);
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
	img->win = win;
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

int	checker(int argc, char **argv)
{
	char	*file;
	char	*fdf;

	if (argc != 2)
		return (1);
	file = argv[1];
	fdf = ".fdf";
	while (file)
	{
		if (*file == '.' && ft_strlen(file) <= 4)
		{
			if (strncmp(file, fdf, ft_strlen(file)) == 0)
				return (0);
			else
				return (1);
		}
		file++;
	}
	return (1);
}

/*void	replace_img(t_data *img)
{
	if (img->win)
	{
		if (img->win->mlx && img->img)
			mlx_destroy_image(img->win->mlx, img->img);
		if (img->win->mlx && img->win->win)
			mlx_destroy_window(img->win->mlx, img->win->win);
		if (img->win->mlx)
		{
			mlx_destroy_display(img->win->mlx);
			free(img->win->mlx);
		}
		free(img->win);
		free(img);
	}
}


float	*gradient(int *start, int *finish, int start_color, int finish_color)
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
