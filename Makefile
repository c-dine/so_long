CC = clang
FLAGS = -Wall -Wextra -Werror
SRC = main.c basics.c ft_map_utils.c gnl.c map_errors.c ft_mlx_utils.c ft_init.c ft_move.c close_destroy.c
SRC_BONUS = ./bonus/main_bonus.c ./bonus/basics_bonus.c ./bonus/ft_map_utils_bonus.c ./bonus/gnl_bonus.c \
			./bonus/map_errors_bonus.c ./bonus/ft_mlx_utils_bonus.c ./bonus/ft_init_bonus.c ./bonus/ft_move_bonus.c \
			./bonus/close_destroy_bonus.c ./bonus/ft_reaper_bonus.c ./bonus/display_msg_bonus.c \
			./bonus/ft_get_position_bonus.c
OBJ = ${SRC:.c=.o}
OBJ_BONUS = ${SRC_BONUS:.c=.o}
NAME = so_long
RM = rm -f

.c.o: so_long
	  ${CC} ${FLAGS} -c -I. $< -o ${<:.c=.o}

${NAME}: ${OBJ} mlx
		${CC} ${FLAGS} ${OBJ} ./minilibx/libmlx_Linux.a -lXext -lX11 -I ./minilibx/include/ -o ${NAME}

all: ${NAME}

clean:
		${RM} ${OBJ} ${OBJ_BONUS}

fclean: clean
		${RM} ${NAME} 

re: fclean all

bonus: ${OBJ_BONUS} mlx
		${CC} ${FLAGS} ${OBJ_BONUS} ./minilibx/libmlx_Linux.a -lXext -lX11 -I ./minilibx/include/ -o ${NAME}

mlx:
	make -C ./minilibx