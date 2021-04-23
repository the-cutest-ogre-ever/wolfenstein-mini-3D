#include "includes.h"

t_player *init_player(int x, int y, char or)
{
	t_player *player;

	player = malloc(sizeof(t_player));
	player->x = x;
	player->y = y;
	player->orientation = or;
	return (player);
}

void print_player_info(t_player *player)
{
	if (player)
		printf("Player: x %d y %d orientation:%c\n",
		 player->x, player->y, player->orientation);
}

void free_player(t_player *player)
{
	free(player);
}