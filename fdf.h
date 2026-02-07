/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssutarmi <ssutarmi@student_42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 19:56:17 by ssutarmi          #+#    #+#             */
/*   Updated: 2026/02/07 16:32:02 by ssutarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "fdf_structs_and_macros.h"

// PARSING.c
t_map	*parsing(int fd);

// MLX_LAUNCH.C

// UTILS.C
t_data	*new_node(void *connection);
int		*space_between_points(t_map *y_head, int w_buffer, int y_buffer);

// DRAWING.C

// DRAWING_UTILS.C
void	pixel_put(t_data *img, int x, int y, int color);
void	line_put(t_data *img, int *x, int y, int color);
void	column_put(t_data *img, int x, int *y, int color);

// CLEANING.C
void	free_struct(t_map *y_head);

#endif
