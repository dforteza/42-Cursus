# Nombre del ejecutable
NAME = libftprintf.a

# Archivo de cabecera
HEADER = printf.h

# Compilador y opciones
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Archivos de implementación
SRC = ft_printf.c \
	ft_utils.c \
	ft_puthex.c \
	ft_putptr.c

# Archivo objeto
OBJ = $(SRC:.c=.o)

# Regla por defecto
all: $(NAME)

# Regla para crear el ejecutable
$(NAME): $(OBJ)
	@echo "Compilando $(NAME)"
	@ar rcs $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "Done !"

# Regla para limpiar los archivos objeto
clean:
	@echo "Remove .o  ..."
	@rm -f $(OBJ)
	@echo "Done !"

# Regla para limpiar los archivos objeto y el ejecutable
fclean: clean
	@echo "Remove lib ..."
	@rm -f $(NAME)
	@echo "Done !"

# Regla para recompilar todo
re: fclean all

# Regla para compilar los archivos objeto
%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re
