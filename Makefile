NAME =			cub3D

LIBFT_DIR =		libft
MINILIBX_DIR =	minilibx

CC =			gcc
FLAGS =			-Wall -Werror -Wextra
LIBS_DIR =		-L./$(LIBFT_DIR) -L./$(MINILIBX_DIR)
LIBS =			-lft -lmlx -lm -lX11 -lXext
RM =			/bin/rm -rf

INCLUDES_DIR =	$(SRC_DIR) $(LIBFT_DIR) $(MINILIBX_DIR)
INCLUDES =		$(INCLUDES_DIR)/error_codes.h $(INCLUDES_DIR)/includes.h \
				$(INCLUDES_DIR)/ubuntu_keys.h $(INCLUDES_DIR)/error_codes.h

SRC_DIR =		./srcs
SRCS =			$(SRC_DIR)/map_handler.c $(SRC_DIR)/view_handler.c \
				$(SRC_DIR)/session_handler.c $(SRC_DIR)/error_handler.c \
				$(SRC_DIR)/01_main_map_validator.c $(SRC_DIR)/parser.c \
				$(SRC_DIR)/color_parser.c $(SRC_DIR)/validator.c

OBJ_DIR =		./objs
OBJS =			$(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all:			$(OBJ_DIR) make_libft make_minilibx $(NAME)

.PONY:			make_libft, make_minilibx, all, clean, fclean, re

$(NAME):		$(OBJS)
				@$(CC) $(FLAGS) $(addprefix -I, $(INCLUDES_DIR)) $(OBJS) $(LIBS_DIR) $(LIBS) -o $@

$(OBJS): 		$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCLLUDES)
				@$(CC) $(FLAGS) -c $(addprefix -I, $(INCLUDES_DIR)) $< $(LIBS_DIR) $(LIBS) -o $@

$(OBJ_DIR):
				@mkdir $@

make_minilibx :	$(MINILIBX_DIR)
				@make -C $<

make_libft :	$(LIBFT_DIR)
				@make bonus -C $<

clean :
				$(RM) $(OBJS) $(OBJ_DIR)
				@make -C $(LIBFT_DIR) clean
				@make -C $(MINILIBX_DIR) clean

fclean :		clean
				$(RM) $(NAME)
				$(RM) *.bmp
				@make -C $(LIBFT_DIR) fclean

re:				fclean all

