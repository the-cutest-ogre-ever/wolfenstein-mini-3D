#include "includes.h"

int handle_game(t_session *session)
{
	t_img *temp;

	if (!session->img_0)
	{
		session->img_0 = init_frame(session->win->mlx_ptr, session->win->x,
							  session->win->y);
		session->img_1 = init_frame(session->win->mlx_ptr, session->win->x,
									session->win->y);
		if (!session->img_0 && !session->img_1)
			destroy_session(session, NULL);
	}
	process_key(cub);
	make_frame(cub);
	mlx_put_image_to_window(cub->win->mlx_ptr, cub->win->win_ptr,
							cub->frm_0->ptr, 0, 0);
	tmp_frm = cub->frm_0;
	cub->frm_0 = cub->frm_1;
	cub->frm_1 = tmp_frm;
	return (0);
}