/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssutarmi <ssutarmi@student_42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:39:29 by ssutarmi          #+#    #+#             */
/*   Updated: 2026/02/09 13:39:36 by ssutarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_struct(t_map *y_head)
{
	t_map	*track;
	int		i;

	i = 0;
	while (y_head)
	{
		i = 0;
		track = y_head->down;
		while (y_head->line[i])
			free_table(y_head->line[i++]);
		free(y_head->line);
		free(y_head);
		y_head = track;
	}
}
