NAME = pipex
LIB = libft.a
LIB_D = libft
SRC = src
INC = inc
OBJ = obj
CC = clang
CFLAGS = -Wall -Wextra -Werror -I $(INC)
SRC_F = $(wildcard $(SRC)/*.c)
INC_F = $(wildcard $(INC)/*.h)
OBJ_F = $(SRC_F:.c=.o)
OBJS = $(subst $(SRC),$(OBJ),$(OBJ_F))


GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;34m
DEF_COLOR = \033[0;39m

all: $(NAME)

$(NAME): $(OBJS) $(LIB_D)/$(LIB)
	@$(CC) $(FLAGS) $^ -o $@
	@echo "$(GREEN)pipex compiled!$(DEF_COLOR)"

$(OBJ)/%.o:	$(SRC)/%.c $(OBJ)
	@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ):
	@mkdir -p $(OBJ)
	@make -C $(LIB_D)
	@echo "$(BLUE)libft is done!$(DEF_COLOR)"

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C $(LIB_D)
	@echo "$(YELLOW)Evrything was cleaned $(DEF_COLOR)"
re: fclean all