OUT = libftprintf.a

SRC = ft_printf.c \
    ft_utils.c \
    ft_puthex.c \
    ft_putptr.c

OBJS = ${SRC:.c=.o}

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I .

.c.o:
	${CC} ${CFLAGS} ${INCLUDE} -c $< -o $@

$(OUT): ${OBJS}
	ar rcs ${OUT} ${OBJS}

all: ${OUT}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${OUT}

re: fclean all

.PHONY: all clean fclean re