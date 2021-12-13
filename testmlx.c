#include "./so_long.h"

int handle_key_events(int keycode)
{
	// printf("You pressed [%d]\n", keycode);
	// W   => 13
	// A   => 0
	// S   => 1
	// D   => 2
	// ESC => 53
	if (keycode == 53)
		exit(0);
	else if (keycode == 13)
		printf("W\n");
	else if (keycode == 0)
		printf("A\n");
	else if (keycode == 1)
		printf("S\n");
	else if (keycode == 2)
		printf("D\n");

	return (0);
}

// int handle_mouse_events(int button_code)
// {
// 	printf("%d\n", button_code);
// 	return (0);
// }

int main(void)
{
	t_map m;
	void *mlx;
	void *mlx_win;
	void *block_img;
	int block_img_width;
	int block_img_height;

	m.width = 16;
	m.height = 10;
	m.scale = 64;
	m.map_matrix = NULL;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, m.width * m.scale, m.height * m.scale + 40, "SoLong");
	block_img = mlx_xpm_file_to_image(mlx, "./assets/block.xpm", &block_img_width, &block_img_height);

	for (int x = 0; x <= m.width * m.scale; x += m.scale)
	{
		for (int y = 0; y <= m.height * m.scale; y += m.scale)
		{
			if (
				x == 0
				|| y == 0
				|| x == m.width * m.scale - m.scale
				|| y == m.height * m.scale - m.scale
				|| (x / m.scale == 2 && y / m.scale == 3)
				|| (x / m.scale == 5 && y / m.scale == 2)
				|| (x / m.scale == 4 && y / m.scale == 8)
			)
				mlx_put_image_to_window(mlx, mlx_win, block_img, x, y + 40);
		}
	}

	mlx_key_hook(mlx_win, handle_key_events, NULL);
	// mlx_mouse_hook(mlx_win, handle_mouse_events, NULL);
	mlx_string_put(mlx, mlx_win, 20, 10, 0x00FFFFFF, "So So Long");

	mlx_loop(mlx);
	return (0);
}
