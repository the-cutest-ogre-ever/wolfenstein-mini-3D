#include "includes.h"

static int	is_color_valid(t_session *session)
{
	if (session->ceiling_color[0] == -1 || session->ceiling_color[1] == -1
		|| session->ceiling_color[2] == -1)
		return (print_error(ERROR_COLOR_C_NEG));
	if (session->floor_color[0] == -1 || session->floor_color[1] == -1
		|| session->floor_color[2] == -1)
		return (print_error(ERROR_COLOR_F_NEG));
	if (session->ceiling_color[0] < 0 || session->ceiling_color[0] > 255
		|| session->ceiling_color[1] < 0 || session->ceiling_color[1] > 255
		|| session->ceiling_color[2] < 0 || session->ceiling_color[2] > 255)
		return (print_error(ERROR_COLOR_C_OUT));
	if (session->floor_color[0] < 0 || session->floor_color[0] > 255
		|| session->floor_color[1] < 0 || session->floor_color[1] > 255
		|| session->floor_color[2] < 0 || session->floor_color[2] > 255)
		return (print_error(ERROR_COLOR_F_OUT));
	return (1);
}

static int	is_resolution_valid (t_session *session)
{
	if (session->resolution[0] == -1 || session->resolution[1] == -1)
		return (print_error(ERROR_RESOL_NEG));
	if (session->resolution[0] < 0 || session->resolution[1] < 0)
		return (print_error(ERROR_RESOL_OUT));
	return (1);
}

static int	is_texture_exist(t_session *session)
{
	if (!session->s)
		return (print_error(ERROR_NO_TEXT_S));
	if (!session->no)
		return (print_error(ERROR_NO_TEXT_NO));
	if (!session->so)
		return (print_error(ERROR_NO_TEXT_SO));
	if (!session->we)
		return (print_error(ERROR_NO_TEXT_WE));
	if (!session->ea)
		return (print_error(ERROR_NO_TEXT_EA));
	return (1);
}

static int	is_player_exist(t_session *session)
{
	if (session->view.direction == '0')
		return (print_error(ERROR_MAP_PLAYER_NO));
	return (1);
}

int	is_session_valid(t_session *session)
{
	return (is_color_valid(session) && is_resolution_valid(session)
		&& is_map_valid(session) && is_texture_exist(session)
		&& is_player_exist(session));
}
