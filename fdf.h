/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssutarmi <ssutarmi@student_42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 19:56:17 by ssutarmi          #+#    #+#             */
/*   Updated: 2026/02/23 17:46:08 by ssutarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "fdf_structs_and_macros.h"

// PARSING.c
t_map	*parsing(char **argv, int x_buffer, int y_buffer);

// MLX_LAUNCH.C

// UTILS.C
t_data	*new_node(void);
int		*swap_two_ints(int *arr);

// DRAWING.C
void	drawing(t_map *head, t_data *img);

// DRAWING_UTILS.C
void	pixel_put(t_data *img, int x, int y, int color);

// CLEANING.C
void	free_struct(t_map *head);

#endif
