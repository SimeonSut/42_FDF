/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssutarmi <ssutarmi@student_42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:38:34 by ssutarmi          #+#    #+#             */
/*   Updated: 2026/03/09 16:35:56 by ssutarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_map	*map_to_list(int fd);
static t_map	*new_point(char *line, int y);
static char		***input_line(char *line);
static bool		map_conformity(t_map *head);

t_map	*parsing(char **argv)
{
	int		fd;
	t_map	*head;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (perror("open"), NULL);
	head = map_to_list(fd);
	if (!head)
		return (NULL);
	if (map_conformity(head) == false)
	{
		free_t_map(head);
		close(fd);
		ft_printf(STDERR_FILENO, "Found wrong line length. Exiting.\n");
		return (NULL);
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

static bool	map_conformity(t_map *head)
{
	int		prev_len;
	int		i;

	i = 0;
	while (head->line[i])
		i++;
	prev_len = i;
	i = 0;
	head = head->down;
	while (head)
	{
		i = 0;
		while (head->line[i])
			i++;
		if (i != prev_len)
			return (false);
		head = head->down;
	}
	return (true);
}
