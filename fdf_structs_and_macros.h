/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_structs_and_macros.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssutarmi <ssutarmi@student_42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 13:22:31 by ssutarmi          #+#    #+#             */
/*   Updated: 2026/03/05 17:04:25 by ssutarmi         ###   ########.fr       */
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
	void		*window;
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
	t_wdata		*window;
}				t_data;

# define WIDTH 1920
# define HEIGHT 1080
# define Z_SCALE 3
# define X 0
# define Y 1
# define R 0
# define G 1
# define B 2
# define RIGHT 2
# define DOWN 3

#endif