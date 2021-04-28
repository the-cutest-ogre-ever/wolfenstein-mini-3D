#include "includes.h"

int main(int argc, char **argv)
{
	t_session *session;

	session = init_session();
	if (argc > 1)
	{
		parse_setting_file(argv[1], session);
		if (session)
		{
			print_session_info(session);
			print_list(session->map);
			if (session->player)
				print_player_info(session->player);
			if (is_session_valid(session))
				printf(">>>>> SESSION IS VALID <<<<<\n");
			else
				printf(">>>>> SESSION IS INVALID <<<<<\n");
			free_session(session);
		}
	}
	return (print_error(ERROR_EMPTY));
}