NAME 		:= 	cub3D

INCLUDES 	:= 	cube3D.h 					\
    			define.h 					\
    			include.h 					\
    			struct.h

SRC 		:=	parsing/error.c 				\
				parsing/parsing.c 			\
				utils/utils.c 				\
				utils/utils2.c 				\
				parsing/map_parsing.c		\
				parsing/metadata_parsing.c	\
				object/string.c					\
				object/string2.c					\
				display/init_mlx.c			\
				display/minimap.c			\
				display/mlx_pixel_put.c			\
				controls/closing.c 			\
				controls/keys.c				\
				controls/move.c				\
				controls/rotate.c				\
				display/raycasting.c		\
				display/offset.c			\
				display/texture.c			\
				display/update.c			\
				main.c

OPATH 		:= 	.obj_dir
OBJ 		:= 	$(addprefix $(OPATH)/,$(SRC:.c=.o))
HEADER 		:= 	$(addprefix includes/,$(INCLUDES))
CFLAGS 		:= 	-Wall -Wextra -Werror
MEMFLAGS 	:= 	-fsanitize=address -g3
LLDB		:=	-g3
MLXPATH    	= mlx_linux
MLX        	= $(DIR_MLX)/libmlx_Linux.a 
MLXFLAGS 	= -lm -Lmlx_linux -lbsd -lmlx_Linux -lXext -lX11


all 			: make_mlx $(NAME)

$(OPATH)/%.o 	: %.c $(HEADER) Makefile
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) 		: $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@ $(MLXFLAGS)

bonus			:
	${MAKE} -C ./ all NAME=cub3D_bonus

leaks 			: CFLAGS += $(MEMFLAGS)
leaks			: all

debug			: CFLAGS += $(LLDB)
debug 			: all

norminette	:	
	norminette $(SRC) $(HEADER)

make_mlx 		:
	@make -C $(MLXPATH) || true

clean_mlx 	:
	@make clean -C $(MLXPATH) || true

clean 			: clean_mlx
	@rm -rf $(OPATH) || true

fclean 			: clean
	rm $(NAME) cub3D_bonus || true

re 					: fclean all

.PHONY 			: clean fclean clean_mlx re make_mlx debug norminette norm
