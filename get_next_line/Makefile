NAME = libgnl.a

FILES = get_next_line.c \
		get_next_line_utils.c

OBJS = $(FILES:.c=.o)
DEPS = $(FILES:.c=.d)

CC = cc
CFLAGS = -Wall -Werror -Wextra

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
	@echo "$(GREEN)✔ $(MAGENTA)created $(GREEN)$(NAME)$(MAGENTA)!$(RESET)"

%.o: %.c
	@$(CC) $(CFLAGS) -MMD $(INCLUDE) -c $< -o $@
	@echo "· compiling get_next_line/$<"

-include $(DEPS)

clean:
	@rm -rf $(OBJS) $(DEPS)

fclean: clean
	@rm -rf $(NAME)
	@echo "$(NAME) was deleted."

re: fclean all

.PHONY: all fclean clean re