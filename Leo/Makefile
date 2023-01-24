NAME		=	cube3d
HEADER		=	display.h
OBJ			=	$(SRC:.c=.o)
OBJMAND		=	$(SRCMAND:.c=.o)

CC		=	gcc

SRCMAND =	./main.c

SRC		=	./init_mlx.c ./mlx_pixel_put.c

all: lib $(NAME)

%.o: %.c fdf.h ./get_next_line/get_next_line.h Makefile ./minilibx/libmlx.a
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME): $(OBJ) $(OBJMAND)
	$(CC) $(OBJ) $(OBJMAND) -Iminilibx minilibx/libmlx.a -framework OpenGL -framework AppKit -o $(NAME)

bonus: lib

lib:
	@$(MAKE) -C ./minilibx/

clean:
	@/bin/rm -f *.o rm *.a
	@$(MAKE) clean -C ./minilibx/

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all bonus lib clean fclean re