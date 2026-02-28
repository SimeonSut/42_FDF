/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssutarmi <ssutarmi@student_42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 19:56:17 by ssutarmi          #+#    #+#             */
/*   Updated: 2026/02/28 17:18:32 by ssutarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "fdf_structs_and_macros.h"

// UTILS.C
t_data	*new_node(void);
int		*swap_two_ints(int *arr);

// PARSING.c
t_map	*parsing(char **argv);

// MLX_LAUNCH.C

// MAPPING.C
t_obj	*mapping(t_map *head);

// DRAWING.C
void	map_to_draw(t_data *img, t_map *head, t_obj *child);

// DRAWING_UTILS.C
void	pixel_put(t_data *img, int x, int y, int color);
int		hexptr_int(char *color);
int		*start_find(t_map *head, t_obj *child, int index);
int		*finish_h_find(t_map *head, t_obj *child, int index);
int		*finish_v_find(t_map *head, t_obj *child, int index);

// CLEANING.C
void	free_struct(t_map *head);

#endif
