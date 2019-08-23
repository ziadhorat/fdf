NAME=fdf
SRCS_PATH=./srcs/
SRCS_FILES=fdf_cal_matrice.c fdf_draw.c fdf_error.c fdf_helper.c fdf_hook.c fdf_matrice.c main.c parse_arg.c
SRCS=$(addprefix $(SRCS_PATH), $(SRCS_FILES))
OBJECTS_PATH=./srcs/
OBJECTS_FILES=$(SRCS_FILES:.c=.o)
OBJECTS=$(addprefix $(OBJECTS_PATH), $(OBJECTS_FILES))
COMPILE=gcc -Wall -Wextra -Werror
INCLUDES=-I./includes -I./libft
HEADER=./includes/fdf.h
MLX=-L/usr/local/lib -I/usr/local/include -lmlx -framework OpenGL -framework AppKit
LIB_NAME=libft.a
LIB_PATH=./libft/
LIB=$(LIB_PATH)$(LIB_NAME)
COLOR_RESET=\033[0m
COLOR_PENDING=\033[0;33m
COLOR_SUCCESS=\033[0;32m
COLOR_DEFAULT=\033[1;34m

all: $(NAME)

$(NAME): $(OBJECTS) $(HEADER)
	@echo "$(LIB_NAME)     [$(COLOR_PENDING)Compiling...$(COLOR_RESET)]"
	@make -C $(LIB_PATH) > /dev/null
	@echo "\033[A\033[K\033[A"
	@echo "$(LIB_NAME) [$(COLOR_SUCCESS)OK$(COLOR_RESET)]"
	@echo "$(NAME)     [$(COLOR_PENDING)Compiling...$(COLOR_RESET)]"
	@$(COMPILE) $(OBJECTS) $(MLX) $(LIB) $(GNL) -o $(NAME) > /dev/null
	@echo "\033[A\033[K\033[A"
	@echo "$(NAME)     [$(COLOR_SUCCESS)OK$(COLOR_RESET)]"
	@echo "        [$(COLOR_SUCCESS)FINISHED$(COLOR_RESET)]"

$(OBJECTS_PATH)%.o: $(SRCS_PATH)%.c
	@mkdir $(OBJECTS_PATH) 2>/dev/null || echo "" > /dev/null
	@$(COMPILE) $(INCLUDES) -c $< -o $@
	@echo "Compiled $@" > /dev/null

clean:
	@make -C $(LIB_PATH) clean > /dev/null
	@rm -rfv $(OBJECTS) > /dev/null

fclean: clean
	@make -C $(LIB_PATH) fclean > /dev/null
	@rm -rfv $(NAME) > /dev/null

re: fclean all

.PHONY: clean fclean re all
