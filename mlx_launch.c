
#include "fdf.h"

static void	tests(t_data *img);

void	initialization(void)
{
	void		*connection;
	void		*window;
	t_data		*img;

	connection = mlx_init();
	img = new_node(connection);
	if (!img)
		return ;
	window = mlx_new_window(connection, WIDTH, HEIGHT, "2nd window");
	tests(img);
	mlx_put_image_to_window(connection, window, img->img, 0, 0);
	mlx_loop(connection);
}

static void	tests(t_data *img)
{
	int	x_arr[2];
	int	y_arr[2];

	x_arr[0] = WIDTH / 4;
	x_arr[1] = x_arr[0] + 50;
	y_arr[0] = HEIGHT / 4;
	y_arr[1] = y_arr[0] + 50;
	line_put(img, x_arr, y_arr[0], 0x00FFFFFF);
	column_put(img, x_arr[0], y_arr, 0x00FFFFFF);
	column_put(img, x_arr[1], y_arr, 0x00FFFFFF);
}
