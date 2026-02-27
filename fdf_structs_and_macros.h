/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_structs_and_macros.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssutarmi <ssutarmi@student_42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 13:22:31 by ssutarmi          #+#    #+#             */
/*   Updated: 2026/02/27 17:54:25 by ssutarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_STRUCTS_AND_MACROS_H
# define FDF_STRUCTS_AND_MACROS_H

# include "Libft/libft.h"
# include "mlx_linux/mlx.h"
# include "mlx_linux/mlx_int.h"
# include <math.h>

typedef struct s_matrice
{
	char				***line;
	int					y;
	struct s_matrice	*down;
}				t_map;

typedef struct s_coordinates
{
	int		***map;
	int		origin[2];
	float	x_unit_v[2];
	float	y_unit_v[2];
	float	z_unit_v[2];
	int		x_gap;
	int		y_gap;
	int		x_map_len;
	int		y_map_len;
	int		sca;
	int		z_map_len;
}				t_obj;

typedef struct s_data
{
	void	*connection;
	void	*window;
	void	*img;
	char	*addr;
	int		bpp;
	int		line;
	int		endi;
}				t_data;

//img == image
//bpp == bits per pixel
//line == line_lenght
//endi == endian

//int offset = (y(WIDTH?) * line_length + x(HEIGHT?) * (bits_per_pixel / 8));

# define WIDTH 1920
# define HEIGHT 1080
# define BUFFER_X 10
# define BUFFER_Y 10
# define Z_SCALE 3
# define X 0
# define Y 1

#endif