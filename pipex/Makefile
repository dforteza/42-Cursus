OUT = pipex

SRC = src/pipex.c src/utils.c
SRCS_BONUS = src_bonus/here_doc.c src_bonus/utils_bonus.c src_bonus/pipex_bonus.c \
                        gnl/get_next_line_bonus.c gnl/get_next_line_utils_bonus.c
OBJS = ${SRC:.c=.o}
OBJS_BONUS = ${SRCS_BONUS:.c=.o}

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g
INCLUDE = -I header -I gnl
LIBFT_PATH = libft
LIBFT = ${LIBFT_PATH}/libft.a

.c.o:
	${CC} ${CFLAGS} ${INCLUDE} -c $< -o $@

$(OUT): ${OBJS} ${LIBFT}
	${CC} ${OBJS} -L ${LIBFT_PATH} -lft -o ${OUT}

bonus: ${OBJS_BONUS} ${LIBFT}
	${CC} ${OBJS_BONUS} -L ${LIBFT_PATH} -lft -o ${OUT}

${LIBFT}:
		${MAKE} -C ${LIBFT_PATH}

all: ${OUT}

clean:
		${MAKE} -C ${LIBFT_PATH} clean
		${RM} ${OBJS} ${OBJS_BONUS}

fclean: clean
		${MAKE} -C ${LIBFT_PATH} fclean
		${RM} ${OUT}

re: fclean all

.PHONY: all clean fclean re bonus