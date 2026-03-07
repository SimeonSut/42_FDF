/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssutarmi <ssutarmi@student_42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:39:29 by ssutarmi          #+#    #+#             */
/*   Updated: 2026/03/07 15:19:55 by ssutarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	destroy_all(t_data *img)
{
	if (img->win)
	{
		free_t_obj(img->child);
		free_t_map(img->head);
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
	exit(0);
}

void	free_t_map(t_map *head)
{
	t_map	*track;
	int		i;

	i = 0;
	while (head)
	{
		i = 0;
		track = head->down;
		while (head->line[i])
			free_table(head->line[i++]);
		free(head->line);
		free(head);
		head = track;
	}
}

void	free_t_obj(t_obj *child)
{
	int		i;
	int		j;

	i = 0;
	while (i <= child->y_map_len)
	{
		j = 0;
		while (j < child->x_map_len)
			free(child->map[i][j++]);
		free(child->map[i]);
		i++;
	}
	free(child->map);
	free(child);
}
