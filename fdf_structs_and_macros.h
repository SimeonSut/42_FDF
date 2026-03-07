/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_structs_and_macros.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssutarmi <ssutarmi@student_42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 13:22:31 by ssutarmi          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/03/07 16:46:26 by ssutarmi         ###   ########.fr       */
=======
/*   Updated: 2026/03/04 13:24:23 by ssutarmi         ###   ########.fr       */
>>>>>>> main
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
	float	ref_pi;
	float	x_unit_v[2];
	float	y_unit_v[2];
	float	z_unit_v[2];
	float	x_gap;
	float	y_gap;
	int		x_map_len;
	int		y_map_len;
	int		sca;
	int		z_map_len;
}				t_obj;

typedef struct s_wdata
{
	void		*mlx;
	void		*win;
}			t_wdata;

typedef struct s_data
{
	void		*img;
	char		*addr;
	int			bpp;
	int			line;
	int			endi;
	t_map		*head;
	t_obj		*child;
	t_wdata		*win;
}				t_data;

<<<<<<< HEAD
# define WIDTH 1280
# define HEIGHT 720
=======
//img == image
//bpp == bits per pixel
//line == line_lenght
//endi == endian

//int offset = (y(WIDTH?) * line_length + x(HEIGHT?) * (bits_per_pixel / 8));


# define WIDTH 1920
# define HEIGHT 1080
# define BUFFER_X 10
# define BUFFER_Y 10
>>>>>>> main
# define Z_SCALE 3
# define X 0
# define Y 1
# define ESC 65307
# define A_L 65361
# define A_U 65362
# define A_R 65363
# define A_D 65364
# define Q 113
# define E 101
# define SCRL_UP 4
# define SCRL_DOWN 5
# define RIGHT 2
# define DOWN 3

#endif