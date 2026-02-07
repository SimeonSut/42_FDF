
#include "fdf.h"

static void	draw_grid(t_map y_head, t_data *img, int *space);

int	drawing(void)
{
	return (0);
}

static void	draw_grid(t_map y_head, t_data *img, int *space)
{
	int		i;

	i = 0;
	while (y_head)
	{
		while (y_head->line[i])
		{
			if (y_head->line[(i + 1)])
				line_put(img, , y_head->y);
		}
		y_head->next;
	}
}
