# **************************************************************** #
#                                                                  #
#        :::        ::::::::::: :::::::::  :::::::::: :::::::::::  #
#       :+:            :+:     :+:    :+: :+:            :+:       #
#      +:+            +:+     +:+    +:+ +:+            +:+        #
#     +#+            +#+     +#++:++#+  :#::+::#       +#+         #
#    +#+            +#+     +#+    +#+ +#+            +#+          #
#   #+#            #+#     #+#    #+# #+#            #+#           #
#  ########## ########### #########  ###            ###            #
#                                                                  #
# **************************************************************** #

NAME = libft.a

FILES = ft_strchr.c    \
		ft_strlen.c    \
		ft_calloc.c    \
		ft_strcat.c    \
		ft_isspace.c   \
		ft_strndup.c   \
		ft_strcmp.c    \
		ft_strdup.c    \
		ft_strncpy.c   \
		ft_strjoin.c   \
		ft_isalpha.c   \
		ft_charjoin.c  \
		ft_strlcpy.c   \
		ft_putstr_fd.c \
		ft_memzero.c   \
		ft_strncmp.c   \
		ft_free_split.c\
		ft_split.c     \
		ft_isdigit.c   \
		ft_itoa.c      \
		ft_atoi.c      \
		ft_isalnum.c   \
		ft_strrchr.c

OBJS = $(FILES:.c=.o)
DEPS = $(FILES:.c=.d)

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

CC = cc
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "$(GREEN)✔ $(MAGENTA)created $(YELLOW)$(NAME)$(MAGENTA)!$(RESET)"

%.o: %.c
	@$(CC) $(CFLAGS) -MMD $(INCLUDE) -c $< -o $@
	@echo "· compiling libft/$<"

-include $(DEPS)

clean:
	@rm -rf $(OBJS) $(DEPS)

fclean: clean
	@rm -rf $(NAME)
	@echo "$(NAME) was deleted."

re: fclean all

.PHONY: all fclean clean re