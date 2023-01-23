NAME 		:= 	cube3D

INCLUDES 	:= 	header_struct_object.h 	\
				include.h 				\
				parsing.h 				\
				utils.h 				\

SRC 		:=	parsing/error.c 			\
				parsing/parsing.c 			\
				parsing/parsing_color.c 	\
				parsing/parsing_files.c 	\
				parsing/parsing_map.c 		\
				object/string/string.c 		\
				main.c
OPATH 		:= 	.obj_dir
OBJ 		:= 	$(addprefix $(OPATH)/,$(SRC:.c=.o))
HEADER 		:= 	$(addprefix includes/,$(INCLUDES)) 	\
				object/string/string.h
CFLAGS 		:= 	-Wall -Wextra -Werror #-fsanitize=address -g3
MLXFLAGS 	:= 	-lbsd -lmlx -lXext -lX11

all 			: $(NAME)

$(NAME) 		: $(OBJ)
	$(CC) $(CFLAGS) $< -o $@ $(MLXFLAGS)

$(OPATH)/%.o 	: %.c $(HEADER) make_mlx Makefile
	$(CC) $(CFLAGS) -c $< -o $@ $(MLXFLAGS)


make_mlx 		:
	@make -C mlx

clean_mlx 		:
	@make clean -C mlx

clean 			:
	@rm -rf $(OPATH)
	@clean_mlx

fclean 			:
	rm $(NAME)

re 				: fclean all

.PHONY 			: all clean fclean clean_mlx re make_mlx
