NAME	= cub3d

FILES	= main.c

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
MLX_A       =   lib/minilibx/libmlx.a

LINK		= $(CUBDATA_A) $(LIBFT_A) $(FT_PRINTF_A) $(GNL_A) $(MLX_A)
INCLUDE		= -I include -I src/cubdata -I lib/libft -I lib/get_next_line -I lib/ft_printf -I lib/minilibx
MAKEFLAGS	+= --no-print-directory

SRC_DIR	= src
OBJ_DIR	= obj

SRC		= $(addprefix $(SRC_DIR)/, $(FILES))
OBJS	= $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))
DEPS	= $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.d, $(SRC))

all: libft printf gnl cubdata mlx $(NAME)

libft: $(LIBFT_A)

$(LIBFT_A):
	@make -C lib/libft

printf: $(FT_PRINTF_A)

$(FT_PRINTF_A):
	@make -C lib/ft_printf

gnl: $(GNL_A)

$(GNL_A):
	@make -C lib/get_next_line

cubdata: $(CUBDATA_A)

$(CUBDATA_A):
	@make -C src/cubdata

mlx: $(MLX_A)

$(MLX_A):
	@printf "· building libmlx.a\n"
	@{ \
		bar=""; \
		width=30; \
		while [ ! -f "$(MLX_A)" ]; do \
			bar="$${bar}~"; \
			printf "\r$(MAGENTA)[%-30s]$(RESET)" "$${bar}"; \
			sleep 0.01; \
			[ "$${#bar}" -ge "$$width" ] && bar=""; \
		done; \
		printf "\r\033[K"; \
	} &
	@make -C lib/minilibx > /dev/null 2>&1 
	@wait
	@echo "$(GREEN)✔ $(MAGENTA)created $(RED)libmlx.a$(MAGENTA)!$(RESET)"

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
	@make -C lib/minilibx clean > /dev/null 2>&1
	@make -C src/cubdata clean
	@if [ -d $(OBJ_DIR) ]; then echo "deleted all object files."; fi
	@$(RM) $(OBJ_DIR)

fclean: clean
	@if [ -f $(LIBFT_A) ]; then make -C lib/libft fclean; fi
	@if [ -f $(FT_PRINTF_A) ]; then make -C lib/ft_printf fclean; fi
	@if [ -f $(GNL_A) ]; then make -C lib/get_next_line fclean; fi
	@if [ -f $(MLX_A) ]; then make -C lib/minilibx clean > /dev/null 2>&1; fi
	@if [ -f $(CUBDATA_A) ]; then make -C src/cubdata fclean; fi
	@if [ -f $(NAME) ]; then echo "./$(NAME) was deleted."; fi
	@if [ -f $(NAME) ]; then $(RM) $(NAME); fi

re: fclean all

.PHONY: all fclean clean re libft printf gnl cubdata mlx
