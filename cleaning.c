/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssutarmi <ssutarmi@student_42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:39:29 by ssutarmi          #+#    #+#             */
/*   Updated: 2026/03/04 22:26:13 by ssutarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	free_int_table(int **table, int line_len);

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

	i = 0;
	while (child->map[i])
		free_int_table(child->map[i++], child->x_map_len);
	free(child->map);
	free(child);
}

static void	free_int_table(int **table, int line_len)
{
	int	i;

	i = 0;
	while (i < line_len)
		free(table[i++]);
	free(table);
}
