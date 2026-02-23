/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_structs_and_macros.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssutarmi <ssutarmi@student_42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 13:22:31 by ssutarmi          #+#    #+#             */
/*   Updated: 2026/02/23 19:28:41 by ssutarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_STRUCTS_AND_MACROS_H
# define FDF_STRUCTS_AND_MACROS_H

# include "Libft/libft.h"
# include "mlx_linux/mlx.h"
# include "mlx_linux/mlx_int.h"
# include <math.h>

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

typedef struct s_matrice
{
	char				***line;
	int					y;
	struct s_matrice	*down;
}				t_map;

typedef struct s_coordinates
{
	int	origin[2];
	int	limit[2];
	int	x_count;
	int	y_count;
	int	z_count;
	int	x_hat_v[2];
	int	y_hat_v[2];
	int	z_hat_v[2];
}				t_obj;

# define WIDTH 960
# define HEIGHT 540
# define BUFFER_X 50
# define BUFFER_Y 50
# define X 0
# define Y 1

#endif