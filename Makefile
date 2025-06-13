NAME = cub3d

FILES = main.c

CC = cc
RM = rm -rf
CFLAGS = -Wall -Werror -Wextra

LIBFT_A = libft/libft.a
FT_PRINTF_A = ft_printf/libftprintf.a

LINK = $(LIBFT_A) $(FT_PRINTF_A)
INCLUDE = -I include
MAKEFLAGS += --no-print-directory

SRC_DIR = src
OBJ_DIR = obj

SRC = $(addprefix $(SRC_DIR)/, $(FILES))
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

all: libft printf $(NAME)

libft:
	@make -C libft

printf:
	@make -C ft_printf

$(NAME): $(LIBFT_A) $(FT_PRINTF_A) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LINK)
	@echo "./$(NAME) was created!"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@echo "· compiling $<"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@make -C libft clean
	@make -C ft_printf clean
	@echo "deleted all object files."
	@$(RM) $(OBJ_DIR)

fclean: clean
	@make -C libft fclean
	@make -C ft_printf fclean
	@$(RM) $(NAME)
	@echo "./$(NAME) was deleted."

re: fclean all

.PHONY: all fclean clean re libft printf
