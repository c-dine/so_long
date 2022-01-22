CC = clang
FLAGS = -Wall -Wextra -Werror -g 
SRC = main.c
OBJ = ${SRC:.c=.o}
NAME = so_long
RM = rm -f

.c.o: so_long
	  ${CC} ${FLAGS} -c -I. $< -o ${<:.c=.o}

${NAME}: ${OBJ}
		${CC} ${FLAGS} ${OBJ} ./minilibx/libmlx_Linux.a -lXext -lX11 -I ./minilibx/include/ -o ${NAME}

all: ${NAME}

clean:
		${RM} ${OBJ}

fclean: clean
		${RM} ${NAME}

re: fclean all