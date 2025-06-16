NAME = cub3d

FILES = main.c                    \
		cubfile_validate.c        \
		cubfile_utils.c           \
		cubarray_parse.c          \
		cubarray_parse_map.c      \
		cubarray_parse_colors.c   \
		cubarray_parse_textures.c \
		cubarray_validate.c       \
		cubdata.c                 \
		array_utils.c             \
		mapindex_utils.c


CC = cc
RM = rm -rf
CFLAGS = -g -Wall -Werror -Wextra

LIBFT_A = libft/libft.a
FT_PRINTF_A = ft_printf/libftprintf.a
GNL_A = get_next_line/libgnl.a

LINK = $(LIBFT_A) $(FT_PRINTF_A) $(GNL_A)
INCLUDE = -I include
MAKEFLAGS += --no-print-directory

SRC_DIR = src
OBJ_DIR = obj

SRC = $(addprefix $(SRC_DIR)/, $(FILES))
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

all: libft printf gnl $(NAME)

libft:
	@make -C libft

printf:
	@make -C ft_printf

gnl:
	@make -C get_next_line

$(NAME): $(LIBFT_A) $(FT_PRINTF_A) $(GNL_A) $(OBJS)
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
	@echo "deleted all object files."
	@$(RM) $(OBJ_DIR)

fclean: clean
	@make -C libft fclean
	@make -C ft_printf fclean
	@make -C get_next_line fclean
	@$(RM) $(NAME)
	@echo "./$(NAME) was deleted."

re: fclean all

.PHONY: all fclean clean re libft printf gnl
