NAME	= cub3d

FILES	= main.c             \
		  cub_player.c       \
		  cub_render.c       \
		  cub_texture.c      \
		  cub_raycast.c      \
		  cub_raycast_init.c \
		  cub_raycast_draw.c

DEF_COLOR = \e[1;39m
RESET = \e[0m
GRAY = \e[1;90m
RED = \e[1;91m
YELLOW = \e[1;93m
GREEN = \e[1;92m
BLUE = \e[1;94m
MAGENTA = \e[1;95m
CYAN = \e[1;96m
WHITE = \e[1;97m
BLINK = \e[5m

CC		= cc
RM		= rm -rf
CFLAGS	= -g -Wall -Werror -Wextra

LIBFT_A		=	lib/libft/libft.a
FT_PRINTF_A	=	lib/ft_printf/libftprintf.a
GNL_A		=	lib/get_next_line/libgnl.a
CUBDATA_A	=	src/cubdata/libcubdata.a
MLX_A       =   lib/mlx/build/libmlx42.a

LINK		= $(CUBDATA_A) $(LIBFT_A) $(FT_PRINTF_A) $(GNL_A) $(MLX_A) -ldl -lglfw -pthread -lm
INCLUDE		= -I include -I src/cubdata -I lib/libft -I lib/get_next_line -I lib/ft_printf -I lib/mlx/include/MLX42
MAKEFLAGS	+= --no-print-directory

SRC_DIR	= src
OBJ_DIR	= obj

SRC		= $(addprefix $(SRC_DIR)/, $(FILES))
OBJS	= $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))
DEPS	= $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.d, $(SRC))

all: libft printf gnl cubdata mlx $(NAME)

libft:
	@make -C lib/libft
	
printf:
	@make -C lib/ft_printf

gnl:
	@make -C lib/get_next_line

cubdata:
	@make -C src/cubdata
	
mlx: $(MLX_A)

$(MLX_A):
	@printf "· building libmlx42.a\n"
	@cmake -S lib/mlx -B lib/mlx/build
	@make -C lib/mlx/build -j4
	@echo "$(GREEN)✔ $(MAGENTA)created $(RED)libmlx42.a$(MAGENTA)!$(RESET)"

$(NAME): $(LIBFT_A) $(FT_PRINTF_A) $(GNL_A) $(CUBDATA_A) $(MLX_A) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LINK)
	@echo "./$(NAME) was created!"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -MMD $(INCLUDE) -c $< -o $@
	@echo "· compiling $<"

-include $(DEPS)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@make -C lib/libft clean
	@make -C lib/ft_printf clean
	@make -C lib/get_next_line clean
	@make -C src/cubdata clean
	@if [ -f $(MLX_A) ]; then rm -rf lib/mlx/build; fi
	@if [ -d $(OBJ_DIR) ]; then echo "deleted all object files."; fi
	@$(RM) $(OBJ_DIR)

fclean: clean
	@if [ -f $(LIBFT_A) ]; then make -C lib/libft fclean; fi
	@if [ -f $(FT_PRINTF_A) ]; then make -C lib/ft_printf fclean; fi
	@if [ -f $(GNL_A) ]; then make -C lib/get_next_line fclean; fi
	@if [ -f $(CUBDATA_A) ]; then make -C src/cubdata fclean; fi
	@if [ -f $(NAME) ]; then echo "./$(NAME) was deleted."; fi
	@if [ -f $(NAME) ]; then $(RM) $(NAME); fi

re: fclean all

.PHONY: all fclean clean re libft printf gnl cubdata mlx
