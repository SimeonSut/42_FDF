/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssutarmi <ssutarmi@student_42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 19:56:17 by ssutarmi          #+#    #+#             */
/*   Updated: 2026/03/06 21:32:32 by ssutarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "fdf_structs_and_macros.h"

// UTILS.C
t_data	*new_node(t_wdata *window, t_map *head, t_obj *child);
int		*swap_two_ints(int *arr);
void	gradiant_find(t_obj *child);

// PARSING.c
t_map	*parsing(char **argv);

// MAPPING.C
t_obj	*mapping(t_map *head);

// DRAWING.C
void	map_to_draw(t_data *img, t_map *head, t_obj *child);

// DRAWING_UTILS.C
void	pixel_put(t_data *img, int x, int y, int color);
int		color_char_int(char *color);
int		*start_find(t_map *head, t_obj *child, int index);
int		*finish_find(t_map *head, t_obj *child, int index, int mode);

// WINDOW.C
void	window_handler(t_data *img, t_wdata *window);

// CLEANING.C
void	free_t_map(t_map *head);
void	free_t_obj(t_obj *child);
void	destroy_all(t_data *img);

#endif
