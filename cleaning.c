/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssutarmi <ssutarmi@student_42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:39:29 by ssutarmi          #+#    #+#             */
/*   Updated: 2026/03/05 17:25:01 by ssutarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
