NAME	= cub3d

FILES	= main.c

CC		= cc
RM		= rm -rf
CFLAGS	= -g -Wall -Werror -Wextra

LIBFT_A		=	lib/libft/libft.a
FT_PRINTF_A	=	lib/ft_printf/libftprintf.a
GNL_A		=	lib/get_next_line/libgnl.a
CUBDATA_A	=	lib/cubdata/libcubdata.a

LINK		= $(CUBDATA_A) $(LIBFT_A) $(FT_PRINTF_A) $(GNL_A)
INCLUDE		= -I include -I lib/cubdata -I lib/libft -I lib/get_next_line -I lib/ft_printf 
MAKEFLAGS	+= --no-print-directory

SRC_DIR	= src
OBJ_DIR	= obj

SRC		= $(addprefix $(SRC_DIR)/, $(FILES))
OBJS	= $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))
DEPS	= $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.d, $(SRC))

all: libft printf gnl cubdata $(NAME)

libft:
	@make -C lib/libft

printf:
	@make -C lib/ft_printf

gnl:
	@make -C lib/get_next_line

cubdata:
	@make -C lib/cubdata

$(NAME): $(LIBFT_A) $(FT_PRINTF_A) $(GNL_A) $(CUBDATA_A) $(OBJS)
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
	@make -C lib/cubdata clean
	@echo "deleted all object files."
	@$(RM) $(OBJ_DIR)

fclean: clean
	@make -C lib/libft fclean
	@make -C lib/ft_printf fclean
	@make -C lib/get_next_line fclean
	@make -C lib/cubdata fclean
	@$(RM) $(NAME)
	@echo "./$(NAME) was deleted."

re: fclean all

.PHONY: all fclean clean re libft printf gnl cubdata
