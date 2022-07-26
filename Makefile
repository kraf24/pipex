NAME = pipex
LIB = libft.a
LIB_D = libft
SRC = src
SRC_B = bonus_src
INC = inc
OBJ = obj
OBJ_K = bonus_obj
CC = clang
CFLAGS = -Wall -Wextra -Werror -I $(INC)
SRC_F = $(shell find ./src -name "*.c")
SRC_BONUS = $(shell find ./bonus_src -name "*.c")
OBJ_F = $(SRC_F:.c=.o)
OBJ_B = $(SRC_BONUS:.c=.o)
OBJS = $(subst $(SRC),$(OBJ),$(OBJ_F))
OBJS_B = $(subst $(SRC_B),$(OBJ_K),$(OBJ_B))


GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;34m
DEF_COLOR = \033[0;39m

all: $(NAME)

$(NAME): $(OBJS) $(LIB_D)/$(LIB)
	@$(CC) $(FLAGS) $^ -o $@
	@echo "$(GREEN)pipex compiled!$(DEF_COLOR)"

bonus:	$(OBJS_B) $(LIB_D)/$(LIB)
	@make -C $(LIB_D)
	@echo "$(BLUE)libft is done!$(DEF_COLOR)"
	@$(CC) $(FLAGS) $^ $(LIB_D)/$(LIB) -o $@
	@echo "$(GREEN)bonus pipex compiled!$(DEF_COLOR)"

$(OBJ)/%.o:	$(SRC)/%.c $(OBJ)
	@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_K)/%.o:	$(SRC_B)/%.c $(OBJ_K)
	@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ):
	@mkdir -p $(OBJ)
	@make -C $(LIB_D)
	@echo "$(BLUE)libft is done!$(DEF_COLOR)"

$(OBJ_K):
	@mkdir -p $(OBJ_K)
	@make -C $(LIB_D)
	@echo "$(BLUE)libft is done!$(DEF_COLOR)"

clean:
	@rm -rf $(OBJ)
	@rm -rf $(OBJ_K)

fclean: clean
	@rm -rf $(NAME)
	@rm -rf bonus
	@make fclean -C $(LIB_D)
	@echo "$(YELLOW)Evrything was cleaned $(DEF_COLOR)"
re: fclean all