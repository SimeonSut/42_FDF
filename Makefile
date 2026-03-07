CC = cc

FLAGS = -Wall -Wextra -Werror

MLXFLAGS = -Imlx_linux -O3

APIFLAGS = -Lmlx_linux -lmlx_Linux -Imlx_linux -lXext -lX11 -lm -lz

SRC = main.c parsing.c utils.c cleaning.c drawing.c drawing_utils.c mapping.c window.c

SRC_BONUS = main.c parsing.c utils.c cleaning.c drawing.c drawing_utils.c mapping.c window_bonus.c transformations.c

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

HDR = fdf.h fdf_structs_and_macros.h

NAME = fdf

all: libft $(NAME)

$(NAME): $(OBJ) 
	@$(CC) $(OBJ) libft.a $(APIFLAGS) -o $@

%.o: %.c $(HDR)
	@$(CC) $(FLAGS) $(MLXFLAGS) -c -g $< -o $@

libft:
	@cd Libft ; make ; make clean ; mv 'libft.a' ..

bonus: libft $(OBJ_BONUS)
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
