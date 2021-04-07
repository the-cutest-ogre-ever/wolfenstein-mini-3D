NAME =			cub3D

CC =			gcc

RM =			/bin/rm -rf

CFLAGS =		-Wall  -Wextra

MLX_FLAGS =		-I/usr/include -Imlx_linux -Lmlx_linux -lmlx  -L/usr/lib -Imlx_linux  -lXext -lX11 -lm -lz

LIBFT =			-I.libft/ -lft

LIBFT_A =		./libft/libft.a

MLX =			-I.minilibx/ -lmlx

MLX_A =			minilibx/libmlx_Linux.a

INCLUDES =		ubuntu_keys.h includes.h

SRCS =			map_handler.c player_handler.c \
				session_handler.c main.c

.PONY: all, clean, fclean, re

OBJS =			$(SRCS:.c=.o)

all:			$(NAME)

$(NAME): 		$(OBJS)
				@make bonus -C ./libft/
				@make -C ./minilibx/
				$(CC) $(CFLAGS) -o $@ $^ $(LIBFT_A) $(MLX_A) $(MLX) $(MLX_FLAGS)

clean :
				$(RM) $(OBJS)
				@make -C libft/ clean
				@make -C minilibx/ clean


fclean :		clean
				$(RM) $(NAME)
				@make -C libft/ fclean

re:				fclean all
