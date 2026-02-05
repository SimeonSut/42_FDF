/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssutarmi <ssutarmi@student_42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 13:22:22 by ssutarmi          #+#    #+#             */
/*   Updated: 2026/02/05 22:43:19 by ssutarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_map	*map_to_list(int fd);
static t_map	*new_point(char *line, int y);
static char		***input_line(char *line);
static void		print_map(t_map *y);

int	main(int argc, char **argv)
{
	t_map	*y_head;
	int		fd;

	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (perror("open"), 1);
	y_head = map_to_list(fd);
	if (!y_head)
		return (1);
	print_map(y_head);
	free_struct(y_head);
	close(fd);
	return (0);
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

static void	print_map(t_map *y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (y)
	{
		i = 0;
		while (y->line[i])
		{
			ft_printf(STDOUT_FILENO,"%s , %s : ", y->line[i][0], y->line[i][1]);
			i++;
		}
		y = y->down;
		j++;
	}
	ft_printf(STDOUT_FILENO, "\n\nthere is %d y layers registerd\n", j);
}
