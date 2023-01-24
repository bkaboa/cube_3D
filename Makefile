NAME 		:= 	cub3D

INCLUDES 	:= 	header_struct_object.h 	\
				include.h 				\
				parsing.h 				\
				utils.h 				\

SRC 		:=	parsing/error.c 			\
				parsing/parsing.c 			\
				utils/utils.c 				\
				parsing/parsing_color.c 	\
				parsing/parsing_files.c 	\
				parsing/parsing_map.c 		\
				object/string/string.c 		\
				main.c



OPATH 		:= 	.obj_dir
OBJ 		:= 	$(addprefix $(OPATH)/,$(SRC:.c=.o))
HEADER 		:= 	$(addprefix includes/,$(INCLUDES)) 	\
				object/string/string.h
CFLAGS 		:= 	-Wall -Wextra -Werror
MLXPATH 	:= 	mlx_linux/
MLXFLAGS 	:= 	-L $(MLXPATH) -lbsd -lmlx_Linux -lXext -lX11
MEMFLAGS 	:= 	-fsanitize=address -g3

all 			: $(NAME)

$(NAME) 		: $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@ $(MLXFLAGS)

$(OPATH)/%.o 	: %.c $(HEADER) make_mlx Makefile
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

leaks 			: CFLAGS += $(MEMFLAGS)
leaks 			: re

make_mlx 		:
	@make -C $(MLXPATH)

clean_mlx 		:
	@make clean -C $(MLXPATH) || true

clean 			: clean_mlx
	@rm -rf $(OPATH) || true

fclean 			: clean
	rm $(NAME) || true

re 				: fclean all

.PHONY 			: all clean fclean clean_mlx re make_mlx
