/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssutarmi <ssutarmi@student_42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:38:34 by ssutarmi          #+#    #+#             */
/*   Updated: 2026/03/12 19:33:58 by ssutarmi         ###   ########.fr       */
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
	if (!head->down || !head->line[1])
	{
		ft_printf(STDERR_FILENO, "Nice try but you should give a wireframe.\n");
		return (free_t_map(head), close(fd), NULL);
	}
	if (map_conformity(head) == false)
		return (free_t_map(head), close(fd), NULL);
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
	int		i;

	if (!line)
		return (NULL);
	i = 0;
	point = malloc(sizeof(t_map));
	if (!point)
		return (free(line), NULL);
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		line[i] = '\0';
	point->line = input_line(line);
	if (!point->line)
		return (free(line), free(point), NULL);
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
	i = 0;
	while (points[i])
		i++;
	result = malloc((i + 1) * sizeof(char **));
	if (!result)
		return (free_table(points), NULL);
	result[i] = NULL;
	i = -1;
	while (points[++i])
		result[i] = ft_split(points[i], ',');
	return (free_table(points), result);
}

static bool	map_conformity(t_map *head)
{
	int	i;
	int	prev_len;

	i = 0;
	while (head->down)
	{
		while (head->line[i])
		{
			if (istr_digits(head->line[i][0]) == false)
				return (ft_printf(STDERR_FILENO, "Non digit map\n"), false);
			i++;
		}
		prev_len = i;
		i = 0;
		head = head->down;
		while (head->line[i])
			i++;
		if (prev_len != i)
			return (ft_printf(STDERR_FILENO, "Wrong line length.\n"), false);
		i = 0;
	}
	return (true);
}
