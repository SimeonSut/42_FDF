CC = cc

FLAGS = -Wall -Wextra -Werror -g

APIFLAGS = -Lmlx_linux -lmlx_Linux -Imlx_linux -lXext -lX11 -lm -lz

SRC = main.c parsing.c utils.c cleaning.c drawing.c drawing_utils.c mapping.c window.c

SRC_BONUS = main.c parsing.c utils.c cleaning.c drawing.c drawing_utils.c mapping.c window_bonus.c transformations.c

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

HDR = fdf.h fdf_structs_and_macros.h

NAME = fdf

all: lib $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(APIFLAGS) libft.a -o $@

%.o: %.c $(HDR)
	@$(CC) $(FLAGS) -Imlx_linux -O3 -c $< -o $@

lib:
	@cd Libft ; make ; make clean ; mv 'libft.a' ..
	@$(MAKE) -C mlx_linux

bonus: lib $(OBJ_BONUS)
	@$(CC) $(OBJ_BONUS) libft.a $(APIFLAGS) -o $(NAME)

clean:
	@rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	@rm -f $(NAME)
	@rm -f libft.h.gch
	@rm -f libft.a
	@rm -f libmlx.a
	@rm -f fdf

re: fclean all

rebonus : fclean bonus

.PHONY: all clean fclean re
