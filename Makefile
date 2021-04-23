NAME =			cub3D

CC =			gcc
FLAGS =			-Wall -Werror -Wextra
MLX_FLAGS =		-lft -lmlx -lm -lX11 -lXext
L_LIBS_DIR =	-L./libft -L./minilibx
RM =			/bin/rm -rf

SRC_DIR =		./srcs
OBJ_DIR =		./obj

LIBFT_DIR =		./libft
MINILIBX_DIR =	./minilibx

INCLUDES_DIR =	$(SRC_DIR) $(LIBFT_DIR) $(MINILIBX_DIR)
INCLUDES =		$(wildcard $(INCLUDES_DIR)/*.h)

SRCS =			$(wildcard $(SRC_DIR)/*.c)
OBJS =			$(SRC_ALL:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

.PONY: libft, minilibx, all, clean, fclean, re

all:			$(OBJ_DIR) libft minilibx $(NAME)

$(NAME):		$(OBJS)
				@$(CC) $(FLAGS) $(addprefix -I, $(INCLUDES_DIR)) $(OBJS) $(L_LIBS_DIR) $(MLX_FLAGS) -o $@

$(OBJ_ALL): 	$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCLLUDES)
				@$(CC) $(FLAGS) -c $(addprefix -I, $(INCLUDES_DIR)) $< $(L_LIBS_DIR) $(MLX_FLAGS) -o $@

libft :			$(LIBFT_DIR)
				@make bonus -C $<

minilibx :		$(MINILIBX_DIR)
				@make -C $<

clean :
				$(RM) $(OBJS)
				@make -C $(LIBFT_DIR) clean
				@make -C $(MINILIBX_DIR) clean

fclean :		clean
				$(RM) $(NAME)
				@make -C $(LIBFT_DIR) fclean

re:				fclean all
