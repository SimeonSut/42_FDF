/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssutarmi <ssutarmi@student_42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:39:29 by ssutarmi          #+#    #+#             */
/*   Updated: 2026/02/18 19:22:59 by ssutarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_struct(t_map *head)
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
