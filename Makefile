NAME 		:= 	cub3D

INCLUDES 	:= 	cube3D.h 					\
    			define.h 					\
    			include.h 					\
    			struct.h

SRC 		:=	parsing/error.c 				\
				parsing/parsing.c 			\
				utils/utils.c 				\
				parsing/take_line.c 			\
				object/string.c					\
				display/init_mlx.c			\
<<<<<<< HEAD
				display/minimap.c			\
				display/mlx_pixel_put.c			\
				display/background.c 			\
				controls/closing.c 			\
				controls/controls.c 			\
=======
>>>>>>> origin/parsing
				main.c
				
				#parsing/parsing_map.c 			\
				#display/minimap.c			\
				#display/mlx_pixel_put.c			\
				#controls/closing.c 			\
				#controls/controls.c 			\
				#display/background.c 			\
				#main.c

UNAME_S 	:= $(shell uname -s)
    ifeq ($(UNAME_S),Linux)
        MLXPATH    	= mlx_linux
        MLX        	= $(DIR_MLX)/libmlx_Linux.a 
        MLXFLAGS 		= -Lmlx_linux -lbsd -lmlx_Linux -lXext -lX11
    endif
    ifeq ($(UNAME_S),Darwin)
        MLXPATH    	= mlx
        MLX        	= $(DIR_MLX)/libmlx.a
        MLXFLAGS 		= -Lmlx -lmlx -framework OpenGL -framework AppKit
    endif

OPATH 		:= 	.obj_dir
OBJ 			:= 	$(addprefix $(OPATH)/,$(SRC:.c=.o))
HEADER 		:= 	$(addprefix includes/,$(INCLUDES))
CFLAGS 		:= 	-Wall -Wextra -Werror
<<<<<<< HEAD
MEMFLAGS 	:= 	-fsanitize=address

all 			: $(NAME)

$(NAME) 		: $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@ -lm $(MLXFLAGS)

=======
MEMFLAGS 	:= 	-fsanitize=address -g3
LLDB			:=	-g3

all 			: $(NAME)

>>>>>>> origin/parsing
$(OPATH)/%.o 	: %.c $(HEADER) make_mlx Makefile
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) 		: $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@ $(MLXFLAGS)

leaks 			: CFLAGS += $(MEMFLAGS)
<<<<<<< HEAD
leaks 			: all
=======
leaks				: all

debug				: CFLAGS += $(LLDB)
debug 			: all

norminette	:	
	norminette $(SRC)
	norminette $(HEADER)
>>>>>>> origin/parsing

make_mlx 		:
	@make -C $(MLXPATH)

clean_mlx 	:
	@make clean -C $(MLXPATH) || true

clean 			: clean_mlx
	@rm -rf $(OPATH) || true

fclean 			: clean
	rm $(NAME) || true

re 					: fclean all

.PHONY 			: all clean fclean clean_mlx re make_mlx debug norminette norm
