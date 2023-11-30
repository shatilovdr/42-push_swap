NAME = push_swap

LIBFT = libft/libft.a

FLAGS = -Wall -Wextra -Werror -g

GREEN = \033[0;32m
NC = \033[0m
SRCS = main.c check_argv.c

all: $(NAME)

$(NAME): $(SRCS) $(LIBFT)
	@cc $(FLAGS) $(SRCS) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)push_swap created successfully!$(NC)"

$(LIBFT): 
	@$(MAKE) -C libft/

clean:
	@$(MAKE) clean -C libft/
	@echo "$(GREEN)Helper files removed!$(NC)"


fclean: clean
	@rm -f $(NAME)
	@$(MAKE) fclean -C libft/
	@echo "$(GREEN)push_swap removed!$(NC)"


re: fclean all
