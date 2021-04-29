#include "includes.h"

void	free_sprites(t_sprite **sprites)
{
	t_sprite *temp;
	t_sprite *next;

	if (!(*sprites) || !(sprites))
		return ;
	temp = *sprites;
	next = NULL;
	while (temp->next)
	{
		next = temp->next;
		free(temp);
		temp = next;
	}
	free(temp);
	*sprites = NULL;
}

t_sprite *get_last_sprite(t_sprite *sprites)
{
	if (!sprites)
		return (NULL);
	while (sprites->next)
		sprites = sprites->next;
	return (sprites);
}

double get_sprite_x(double x, double y, t_session *session)
{
	double mid_dist;
	double sprite_x;

	x = x - session->ray->x;
	y = y - session->ray->y;
	mid_dist = session->ray->cos * y + -session->ray->sin * x;
	sprite_x = (session->blk_x / 2) + mid_dist;
	if (sprite_x < 0 || sprite_x > session->blk_x)
		sprite_x = -1.0;
	return (sprite_x / session->blk_x);
}

t_sprite	create_sprite(t_sprite *prev_sprite, char val, t_session *session)
{
	t_sprite *new_sprite;
	double x;
	double y;

	new_sprite = (t_sprite *) malloc(sizeof(t_sprite));
	if (!new_sprite)
		destroy_session(session, ERROR_MEMORY);
	new_sprite->next = NULL;
	new_sprite->prev = prev_sprite;
	if (val == '2')
		new_sprite->text = session->s_text->img_data;
	modf(session->ray->x / session->blk_x, &x);
	modf(session->ray->y / session->blk_y, &y);
	x = (x + 0.5) * session->blk_x;
	y = (y + 0.5) * session->blk_y;
	new_sprite->sprite_dist = sqrt(pow(x - session->view->x, 2) +
			pow(y - session->view->y, 2));
	new_sprite->sprite_x = get_sprite_x(x, y, session);
	return (new_sprite);
}

void add_sprite(char val, t_session *session)
{
	t_sprite *sprites;

	sprites = session->ray->sprite;
	if (!sprites)
	{
		session->ray->sprite = create_sprite(NULL, val, session);
		return ;
	}
	else
	{
		while (sprites->next)
			sprites = sprites->next;
		sprites->next = create_sprite(sprites, val, session);
	}

}