# Nombre del ejecutable
# Archivo de cabecera
HEADER = libft.h
NAME = libft.a

# Compilador y opciones
CC = gcc
CFLAGS = -g -Wall -Wextra -Werror

# Archivos de implementación
SRC = ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
      	ft_isprint.c \
		ft_strlen.c \
		ft_memset.c \
		ft_bzero.c \
      	ft_memcpy.c \
	  	ft_memmove.c \
	  	ft_strlcpy.c \
	  	ft_strlcat.c \
      	ft_toupper.c \
	  	ft_tolower.c \
	  	ft_strchr.c \
	  	ft_strrchr.c \
      	ft_strncmp.c \
	  	ft_memchr.c  \
	  	ft_memcmp.c \
	  	ft_strnstr.c \
      	ft_atoi.c \
	  	ft_strdup.c \
	  	ft_calloc.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c

BONUS_SRC = ft_lstnew_bonus.c \
			ft_lstadd_front_bonus.c \
			ft_lstsize_bonus.c \
			ft_lstlast_bonus.c \
			ft_lstadd_back_bonus.c \
			ft_lstdelone_bonus.c \
			ft_lstclear_bonus.c \
			ft_lstiter_bonus.c \
			ft_lstmap_bonus.c

# Archivo objeto
OBJ = $(SRC:.c=.o)

# Archivos objeto adicionales para bonus
BONUS_OBJ = $(BONUS_SRC:.c=.o)

# Añadir los archivos objeto de bonus a la lista de objetos
# Regla por defecto
all: $(NAME)

# Regla para crear el ejecutable
$(NAME): $(OBJ)
	@echo "Compilando $(NAME)"
	@ar rcs $(NAME) $(OBJ)

# Regla para compilar los archivos objeto de bonus
bonus: $(OBJ) $(BONUS_OBJ)
	@echo "Compilando archivos bonus"
	@ar rcs $(NAME) $(OBJ) $(BONUS_OBJ)

# Regla para limpiar los archivos objeto
clean:
	@rm -f $(OBJ) $(BONUS_OBJ)

# Regla para limpiar los archivos objeto y el ejecutable
fclean: clean
	@rm -f $(NAME)

# Regla para recompilar todo
re: fclean all

# Regla para compilar los archivos objeto
%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re
