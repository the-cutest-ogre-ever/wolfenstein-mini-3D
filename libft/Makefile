# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ijose <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/01 17:25:45 by ijose             #+#    #+#              #
#    Updated: 2020/11/28 14:13:27 by ijose            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		= libft.a

CC			= gcc

CFLAGS		= -Wall -Werror -Wextra

HEADERS		= libft.h

SRCS		= ft_putnbr_fd.c ft_putendl_fd.c ft_putstr_fd.c ft_putchar_fd.c \
              ft_strmapi.c ft_itoa.c ft_split.c ft_strtrim.c ft_strjoin.c \
              ft_substr.c ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c \
              ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memccpy.c \
              ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
              ft_strchr.c ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strlen.c \
              ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c \
              get_next_line.c


BONUS		= ft_lstmap.c ft_lstiter.c ft_lstclear.c ft_lstdelone.c \
              ft_lstadd_back.c ft_lstlast.c ft_lstsize.c ft_lstadd_front.c ft_lstnew.c

OBJS		= ${SRCS:.c=.o}

OBJ_BONUS	= $(BONUS:.c=.o)

RM			= rm -f

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS} ${HEADERS}
			ar rc ${NAME} ${OBJS}
			ranlib ${NAME}

all:		${NAME}

bonus:		${NAME} ${OBJ_BONUS}
			ar rc ${NAME} ${OBJ_BONUS}
			ranlib ${NAME}
		
clean:
			${RM} ${OBJS} ${OBJ_BONUS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re bonus