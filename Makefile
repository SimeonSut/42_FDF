CC = cc

FLAGS = -Wall -Wextra -Werror

MLXFLAGS = -Imlx_linux -O3

APIFLAGS = -Lmlx_linux -lmlx_Linux -Imlx_linux -lXext -lX11 -lm -lz

SRC = main.c parsing.c utils.c mlx_launch.c cleaning.c drawing.c drawing_utils.c

OBJ = $(SRC:.c=.o)

HDR = fdf.h

NAME = fdf

all: libft $(NAME)

$(NAME): $(OBJ) 
	@$(CC) $(OBJ) libft.a $(APIFLAGS) -o $@

%.o: %.c $(HDR)
	@$(CC) $(FLAGS) $(MLXFLAGS) -c $< -o $@

libft:
	@cd Libft ; make ; make clean ; mv 'libft.a' ..

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)
	@rm -f libft.h.gch
	@rm -f libft.a
	@rm -f libmlx.a
	@rm -f fdf

re: fclean all

.PHONY: all clean fclean re
