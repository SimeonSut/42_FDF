/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssutarmi <ssutarmi@student_42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:38:34 by ssutarmi          #+#    #+#             */
/*   Updated: 2026/02/09 19:47:02 by ssutarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_map	*map_to_list(int fd);
static t_map	*new_point(char *line, int y);
static char		***input_line(char *line);
static void		set_proportions(t_map *y_head, int x_buf, int y_buf);

t_map	*parsing(char **argv, int x_buf, int y_buf)
{
	int		fd;
	t_map	*y_head;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (perror("open"), NULL);
	y_head = map_to_list(fd);
	if (!y_head)
		return (NULL);
	set_proportions(y_head, x_buf, y_buf);
	return (y_head);
}

static t_map	*map_to_list(int fd)
{
	int		y;
	char	*line;
	t_map	*y_head;
	t_map	*y_lvl;

	y = 0;
	line = get_next_line(fd);
	y_head = new_point(line, y++);
	if (!y_head)
	{
		free(line);
		return (NULL);
	}
	y_lvl = y_head;
	free(line);
	while (y_lvl)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		y_lvl->down = new_point(line, y++);
		y_lvl = y_lvl->down;
		free(line);
	}
	return (y_head);
}

static t_map	*new_point(char *line, int y)
{
	t_map	*point;

	if (!line)
		return (NULL);
	point = malloc(sizeof(t_map));
	if (!point)
	{
		free(line);
		return (NULL);
	}
	point->line = input_line(line);
	if (!point->line)
	{
		free(line);
		free(point);
		return (NULL);
	}
	point->y = y;
	point->down = NULL;
	return (point);
}

static char	***input_line(char *line)
{
	int		i;
	char	**points;
	char	***result;

	i = 0;
	points = ft_split(line, ' ');
	if (!points)
		return (NULL);
	while (points[i])
		i++;
	result = malloc((i + 1) * sizeof(char **));
	if (!result)
	{
		free_table(points);
		return (NULL);
	}
	result[i] = NULL;
	i = 0;
	while (points[i])
	{
		result[i] = ft_split(points[i], ',');
		i++;
	}
	free_table(points);
	return (result);
}

static void	set_proportions(t_map *y_head, int x_buf, int y_buf)
{
	int		y_ini;
	int		x_ini;
	int		y_sep;
	t_map	*track;

	track = y_head;
	while (track->down)
		track = track->down;
	y_sep = ((HEIGHT / 100) * (100 - y_buf)) / track->y;
	y_head->start[X] = (WIDTH / 100) * (x_buf / 2);
	y_head->start[Y] = ((HEIGHT / 100) * (y_buf / 2));
	x_ini = y_head->start[X];
	y_ini = y_head->start[Y];
	track = y_head->down;
	while (track)
	{
		track->start[X] = x_ini;
		track->start[Y] = y_ini + (y_sep * track->y);
		track = track->down;
	}
}
