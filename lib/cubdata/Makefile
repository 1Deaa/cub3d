NAME = libcubdata.a

FILES = cubfile_validate.c           \
		cubfile_utils.c              \
		cubarray_parse.c             \
		cubarray_parse_map.c         \
		cubarray_parse_colors.c      \
		cubarray_parse_colors_util.c \
		cubarray_parse_textures.c    \
		cubarray_validate.c          \
		cubdata.c                    \
		array_utils.c                \
		array_utils2.c               \
		cubdata_verify.c             \
		mapindex_utils.c             \
		mapindex.c

CC = cc
RM = rm -rf
CFLAGS = -Wall -Werror -Wextra

LINK = $(LIBFT_A) $(FT_PRINTF_A) $(GNL_A)
INCLUDE = -I . -I ../libft -I ../ft_printf -I ../get_next_line
MAKEFLAGS += --no-print-directory

SRC_DIR = src
OBJ_DIR = obj

SRC = $(addprefix $(SRC_DIR)/, $(FILES))
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))
DEPS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.d, $(SRC))
# COLORS

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

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "$(GREEN)✔ $(MAGENTA)created $(WHITE)$(NAME)$(MAGENTA)!$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -MMD $(INCLUDE) -c $< -o $@
	@echo "· compiling $<"

-include $(DEPS)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@$(RM) $(OBJ_DIR) $(DEPS)

fclean: clean
	@$(RM) $(NAME)
	@echo "$(NAME) was deleted."

re: fclean all

.PHONY: all fclean clean re libft printf gnl
