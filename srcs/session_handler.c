#include "includes.h"


void	destroy_img(t_img *img, void *mlx_ptr)
{
	if (img->img_ptr)
		mlx_destroy_image(mlx_ptr, img->img_ptr);
	free(img);
}


void	destroy_text(t_session *session)
{
	if (session->no_text)
		destroy_img(session->no_text, session->win->mlx_ptr);
	if (session->so_text)
		destroy_img(session->so_text, session->win->mlx_ptr);
	if (session->we_text)
		destroy_img(session->we_text, session->win->mlx_ptr);
	if (session->ea_text)
		destroy_img(session->ea_text, session->win->mlx_ptr);
	if (session->s_text)
		destroy_img(session->s_text, session->win->mlx_ptr);
}

void	destroy_win(t_win *win)
{
	if (win->win_ptr)
		mlx_destroy_window(win->mlx_ptr, win->win_ptr);
	if (win->mlx_ptr)
		free(win->mlx_ptr);
	free(win);
}

void	destroy_ray(t_ray *ray)
{
	t_sprite *current;

	current = ray->sprite;
	while (ray->sprite)
	{
		current = current->next;
		free(ray->sprite);
		ray->sprite = current;
	}
	free(ray);
}


void	destroy_session(t_session *session, char *error_code)
{
	if (session->map)
		free_map(&session->map);
	if (session->win)
		destroy_win(session->win);
	if (session->view)
		free(session->view);
	if (session->ray)
		destroy_ray(session->ray);
	if (session->img_0)
		destroy_img(session->img_0, session->win->mlx_ptr);
	if (session->img_1)
		destroy_img(session->img_1, session->win->mlx_ptr);
	destroy_text(session);
	free(session->no);
	free(session->so);
	free(session->ea);
	free(session->we);
	free(session->s);
	free(session);
	print_error(error_code);
}
