CC = cc
AR = ar
ARFLAGS = -rcs
FLAGS = -Wall -Wextra -Werror -Imlx
SRC =

OBJ = $(SRC:.c=.o)

HDR = fdf.h

NAME = fdf

all: $(NAME)

$(NAME): $(OBJ)
	@$(AR) $(ARFLAGS) $@ $^
	@make clean

%.o: %.c $(HDR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)
	@rm -f libft.h.gch

re: fclean all

.PHONY: all clean fclean re
