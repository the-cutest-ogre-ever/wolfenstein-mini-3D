#include "../includes.h"

typedef struct  s_vars {
	void        *mlx;
	void        *win;
	void		*img;
}               t_vars;

int             close_window(int keycode, t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
}

int             key_hook(int keycode, t_vars *vars)
{
	if (keycode == X_EVENT_KEY_EXIT || keycode == KEY_ESC)
	{
		printf("Exiting program...\n");
		close_window(keycode, vars);
		exit(0);
	}
}

int main(void)
{
	t_vars	vars;
	char *path = "cat.xpm";

	int		img_width;
	int 	img_height;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 800, 800, "iMaGe");
	mlx_key_hook(vars.win, key_hook, &vars);
	printf("1\n");
	vars.img = mlx_xpm_file_to_image(vars.mlx, path,
	 &img_width, &img_height);
	printf("2\n");
	if (vars.img != NULL)
		printf("image exists\n");
	else
		printf("image doesn't exist\n");
	if (vars.img)
		mlx_put_image_to_window(vars.mlx, vars.win, vars.img, 80, 80);
	printf("3\n");
	mlx_loop(vars.mlx);
	return (0);
}