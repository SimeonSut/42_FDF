/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssutarmi <ssutarmi@student_42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:38:34 by ssutarmi          #+#    #+#             */
/*   Updated: 2026/02/18 19:54:48 by ssutarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_map	*map_to_list(int fd);
static t_map	*new_point(char *line, int y);
static char		***input_line(char *line);
static void		set_proportions(t_map *head, int x_buf, int y_buf);

t_map	*parsing(char **argv, int x_buf, int y_buf)
{
	int		fd;
	t_map	*head;
	t_map	*track;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (perror("open"), NULL);
	head = map_to_list(fd);
	if (!head)
		return (NULL);
	set_proportions(head, x_buf, y_buf);
	track = head->down;
	while (track)
	{
		track->r_vect[X] = head->r_vect[X];
		track->r_vect[Y] = head->r_vect[Y];
		track->d_vect[X] = head->d_vect[X];
		track->d_vect[Y] = head->d_vect[Y];
		track = track->down;
	}
	return (head);
}

static t_map	*map_to_list(int fd)
{
	int		y;
	char	*line;
	t_map	*head;
	t_map	*y_lvl;

	y = 0;
	line = get_next_line(fd);
	head = new_point(line, y++);
	if (!head)
	{
		free(line);
		return (NULL);
	}
	y_lvl = head;
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
	return (head);
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

static void	set_proportions(t_map *head, int x_buf, int y_buf)
{
	int		x_span;
	int		y_span;
	int		iso_x;
	t_map	*track;

	x_span = WIDTH / 100 * (100 - x_buf);
	y_span = HEIGHT / 100 * (100 - y_buf);
	iso_x = y_span / sin(M_PI_2) * sin(M_PI / 3);
	track = head;
	while (track->down)
		track = track->down;
	head->start[X] = WIDTH / 100 * (x_buf / 2) + iso_x;
	head->start[Y] = HEIGHT / 100 * (y_buf / 2);
	head->d_vect[X] = (y_span / sin(M_PI_2) * sin(M_PI / 3)) / track->y * -1;
	head->d_vect[Y] = sqrt(pow(y_span, 2) + pow(iso_x, 2)) / track->y;
	head->r_vect[X] = head->d_vect[X] * -1;
	head->r_vect[Y] = head->d_vect[Y];
	track = head->down;
	while (track)
	{
		track->start[X] = head->start[X] + head->d_vect[X] * track->y;
		track->start[Y] = head->start[Y] + head->d_vect[Y] * track->y;
		track = track->down;
	}
}


// sin of a / ||a|| == sin of b / ||b|| == sin of c / ||c||