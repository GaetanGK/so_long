SRC =	srcs/parsing.c \
		srcs/parsing_utils.c \
		srcs/parsing_map.c \
		srcs/lib_utils.c \
		srcs/error.c \
		srcs/get_next_line.c \
		srcs/get_next_line_utils.c \
		srcs/get_next_line_utils2.c \
		srcs/raycasting.c \
		srcs/raycasting_key.c \
		srcs/raycasting_init.c \
		srcs/raycasting_render.c \
		srcs/raycasting_draw.c \
		srcs/raycasting_utils.c

OBJS= $(SRC:.c=.o)

INC = -I inc -I ${MLX_DIR}

NAME = so_long

MLX_DIR = minilibx-linux

MLX = libmlx.a 

CC = clang

CFLAGS = -Wall -Wextra -Werror -g

.c.o :
	${CC} ${CFLAGS} ${INC} -c $< -o ${<:.c=.o}

all : ${NAME}

$(NAME) : ${OBJS}
	make -C ${MLX_DIR}
	${CC} $(CFLAGS) -o $(NAME) $(OBJS) -L $(MLX_DIR) -lm -lX11 -lXext -lmlx

clean :    
	make clean -C ${MLX_DIR}
	rm -rf ${OBJS}

fclean : clean
		rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re