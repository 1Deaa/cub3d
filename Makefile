NAME = cub3d

FILES = main.c


CC = cc
RM = rm -rf
CFLAGS = -g -Wall -Werror -Wextra

LIBFT_A = libft/libft.a
FT_PRINTF_A = ft_printf/libftprintf.a
GNL_A = get_next_line/libgnl.a
CUBDATA_A = cubdata/libcubdata.a

LINK = $(CUBDATA_A) $(LIBFT_A) $(FT_PRINTF_A) $(GNL_A)
INCLUDE = -I include -I cubdata -I libft -I get_next_line -I ft_printf 
MAKEFLAGS += --no-print-directory

SRC_DIR = src
OBJ_DIR = obj

SRC = $(addprefix $(SRC_DIR)/, $(FILES))
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

all: libft printf gnl cubdata $(NAME)

libft:
	@make -C libft

printf:
	@make -C ft_printf

gnl:
	@make -C get_next_line

cubdata:
	@make -C cubdata

$(NAME): $(LIBFT_A) $(FT_PRINTF_A) $(GNL_A) $(CUBDATA_A) $(OBJS)
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
	@make -C get_next_line clean
	@make -C cubdata clean
	@echo "deleted all object files."
	@$(RM) $(OBJ_DIR)

fclean: clean
	@make -C libft fclean
	@make -C ft_printf fclean
	@make -C get_next_line fclean
	@make -C cubdata fclean
	@$(RM) $(NAME)
	@echo "./$(NAME) was deleted."

re: fclean all

.PHONY: all fclean clean re libft printf gnl cubdata
