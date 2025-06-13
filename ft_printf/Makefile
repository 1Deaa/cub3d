NAME	= libftprintf.a
# FILES

SRCS	=	ft_printf.c ft_choose.c ft_print_ptr.c \
		ft_putstr.c ft_putnbr.c ft_putchar.c \
		ft_putunsigned.c ft_dectohex_s.c ft_dectohex_c.c \

# VARIABLES

AR = ar rcs

RM = rm -f

OBJS	= $(SRCS:.c=.o)

CC		= cc
CFLAGS	= -Wall -Werror -Wextra
INCLUDE = -I ../include
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

# START HERE |
#            v

all: $(NAME) 

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@echo "$(GREEN)✔ $(MAGENTA)created $(CYAN)$(NAME)$(MAGENTA)!$(RESET)"

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@echo "· compiling ft_printf/$<"

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all fclean clean re
