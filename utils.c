/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssutarmi <ssutarmi@student_42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 19:54:01 by ssutarmi          #+#    #+#             */
/*   Updated: 2026/03/14 14:03:55 by ssutarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_data	*new_node(t_wdata *win, t_map *head, t_obj *child)
{
	t_data	*img;

	img = malloc (sizeof(t_data));
	if (!img)
		return (NULL);
	img->img = mlx_new_image(win->mlx, WIDTH, HEIGHT);
	if (!img->img)
	{
		free(img);
		return (NULL);
	}
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line, &img->endi);
	if (!img->addr)
	{
		free(img);
		return (NULL);
	}
	img->head = head;
	img->child = child;
	img->win = win;
	return (img);
}

int	*swap_two_ints(int	*arr)
{
	int	tmp;

	tmp = arr[0];
	arr[0] = arr[1];
	arr[1] = tmp;
	return (arr);
}

void	gradiant_find(t_obj *child)
{
	int	i;
	int	j;

	i = 0;
	while (i < child->y_map_len)
	{
		j = 0;
		while (j < child->x_map_len)
		{
			if ((j + 1) < child->x_map_len)
				child->map[i][j][RIGHT] = child->map[i][(j + 1)][1];
			if ((i + 1) < child->y_map_len)
				child->map[i][j][DOWN] = child->map[(i + 1)][j][1];
			j++;
		}
		i++;
	}
}

int	checker(int argc, char **argv)
{
	char	*file;
	char	*fdf;

	if (argc != 2)
	{
		ft_printf(STDERR_FILENO, "incorrect input\n");
		return (1);
	}
	file = argv[1];
	fdf = ".fdf";
	while (file)
	{
		if (*file == '.' && ft_strlen(file) <= 4)
		{
			if (strncmp(file, fdf, ft_strlen(file)) == 0)
				return (0);
			else
				return (1);
		}
		file++;
	}
	return (1);
}

bool	istr_digits(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (ft_isdigit(line[i]) == 0)
		{
			if (line[i] == '-' && i == 0)
			{
				i++;
				continue ;
			}
			if (!line[(i + 1)] && line[i] == '\n')
			{
				i++;
				continue ;
			}
			return (false);
		}
		i++;
	}
	return (true);
}
