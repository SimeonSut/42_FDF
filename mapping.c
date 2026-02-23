#include <fdf.h>

static void	x_y_z_count_setup(t_obj *target);
static int	*x_hat_v_setup(t_map *head);
static int	*y_hat_v_setup(t_map *head);
static int	*z_hat_v_setup(t_map *head);

void	mapping(t_map *head)
{
	t_obj	*child;

	child = malloc(sizeof(child));
	if (!child)
		return ;
	child->origin[X] = WIDTH / 100 * (BUFFER_X / 2);
	child->origin[Y] = HEIGHT / 100 * (BUFFER_Y / 2);
	child->limit[X] = WIDTH - child->origin[X];
	child->limit[Y] = HEIGHT - child->origin[Y];
	x_y_z_count_setup(child);
	child->x_hat_v = x_hat_v_setup(head);
}

static void	x_y_z_count_setup(t_obj *target)
{
	int		i;
	int		h;
	int		tmp;

	h = 0;
	while (head->down)
	{
		i = 0;
		while (head->line[i])
		{
			tmp = ft_atoi(line[i]);
			if (tmp > h)
				h = tmp;
			i++;
		}
		head->down;
	}
	child->x_count = i;
	child->y_count = head->y;
	child->z_count = h;
}

static int	*x_hat_v_setup(t_map *head)
{
	return (0);
}

static int	*y_hat_v_setup(t_map *head)
{
	return (0);
}

static int	*z_hat_v_setup(t_map *head)
{
	return (0);
}
