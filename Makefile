#PUSH_SWAP_PROJECT_MAKEFILE
include lib/libft/.make
NAME			:=	push_swap
BONUS			:=	checker
SRCS_NAME		:=	check_argv.c check_one_arg.c push_swap.c create_list.c sort.c sort_utils2.c sort_utils.c stack_operations.c operations_a.c operations_b.c
BONUS_SRCS_NAME	:=	check_argv.c check_one_arg.c push_swap.c create_list.c sort.c sort_utils2.c sort_utils.c stack_operations.c operations_a.c operations_b.c
SRCS_PATH		:=	srcs/
SRCS			:=	main.c $(addprefix $(SRCS_PATH), $(SRCS_NAME))
BONUS_SRCS		:=	checker.c $(addprefix $(SRCS_PATH), $(BONUS_SRCS_NAME))


LIBFT_PATH		:=	lib/$(LIBFT_PATH)
LIBFT 			:=	$(addprefix $(LIBFT_PATH), $(LIBFT))
LIBFT_SOURSES 	:=	$(addprefix $(LIBFT_PATH), $(LIBFT_SOURSES))

all: $(NAME)

$(NAME): $(LIBFT) $(SRCS) 
	@$(CC) $(FLAGS) $(LIBFT) $(SRCS)  -o $(NAME)
	@echo "$(GREEN)\n------------->push_swap created successfully!<------------$(NC)"

bonus: $(BONUS)

$(BONUS):  $(LIBFT) $(BONUS_SRCS)
	@$(CC) $(FLAGS) $(LIBFT) $(BONUS_SRCS) -o $(BONUS)
		@echo "$(GREEN)\n------------->checker created successfully!<-------------$(NC)"

$(LIBFT): $(LIBFT_SOURSES)
	@$(MAKE) -C $(LIBFT_PATH)

clean:
	@$(MAKE) clean -C $(LIBFT_PATH)
	@echo "$(GREEN)*.o files removed!$(NC)"


fclean: clean
	@rm -f $(NAME)
	@rm -f $(BONUS)
	@$(MAKE) fclean -C $(LIBFT_PATH)
	@echo "$(GREEN)All files removed!$(NC)"

re: fclean all
