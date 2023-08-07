NAME = pipex
GCC = gcc
FLAGS = -Wall -Wextra -Werror -fsanitize=address -g3

SRCS = Mandatory/pipex.c Mandatory/pipex_utils.c Mandatory/execution.c Mandatory/pipex_utils2.c
OBJS = $(SRCS:.c=.o)

LIBFT_MAKE = make all -C libft
LIBFT_CP = cp libft/libft.a .

RM = rm -f

# Colors and text formatting
RESET = \033[0m
BOLD = \033[1m
DIM = \033[2m
UNDERLINE = \033[4m
BLINK = \033[5m
INVERT = \033[7m
LIGHT_BLUE = \033[94m
YELLOW = \033[93m

all: $(NAME)

%.o: %.c
	@$(GCC) -c $(CFLAGS) $< -o ${<:.c=.o}

$(NAME): $(OBJS)
	@$(LIBFT_MAKE)
	@$(LIBFT_CP)
	@$(GCC) $(FLAGS) -o $(NAME) $(OBJS) libft.a
	@echo "\n\n"
	@echo "$(YELLOW)now just ./pipex infile "cmd" "cmd2" outfile$(RESET)"

# bonus: ${BONUS_OBJS}
# 	${RM} $(OBJS)
# 	$(LIBFT_MAKE)
# 	$(LIBFT_CP)
# 	$(GNL_MAKE)
# 	$(GNL_CP)
# 	$(GCC) $(FLAGS) -o $(NAME) $(BONUS_OBJS) libft.a gnl.a

clean:
	@$(RM) $(OBJS)

fclean:
	@echo "$(BOLD)$(LIGHT_BLUE)Cleaning all .o files...$(REST)\n"
	@$(RM) $(NAME)
	@make fclean -C libft
	@$(RM) libft.a
	@make clean
	@echo "\n$(BOLD)$(YELLOW)Clean Successfully$(RESET)"

re: fclean all

files:
	@touch infile
	@touch outfile
	@echo "\n$(BOLD)$(YELLOW)infile and outfile created$(RESET)"

clean_files:
	@echo "$(BOLD)$(LIGHT_BLUE)Cleaning files...$(REST)\n"
	@rm infile
	@rm outfile
	@echo "$(BOLD)$(YELLOW)removed successfully :D$(RESET)"

.PHONY: all clean fclean re files bonus clean_files