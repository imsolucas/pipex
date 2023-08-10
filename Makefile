NAME = pipex
GCC = gcc
FLAGS = -Wall -Wextra -Werror -ggdb -fsanitize=address

SRCS = Mandatory/pipex.c Mandatory/pipex_utils.c Mandatory/execution.c Mandatory/pipex_utils2.c
BONUS_SRCS = Bonus/pipex_bonus.c Bonus/pipex_bonus_utils.c Bonus/execution.c
BONUS_OBJS	= $(BONUS_SRCS:.c=.o)
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
	@${RM} $(BONUS_OBJS)
	@$(LIBFT_MAKE)
	@$(LIBFT_CP)
	@$(GCC) $(FLAGS) -o $(NAME) $(OBJS) libft.a
	@echo "\n\n"
	@echo "$(YELLOW)now just ./pipex infile "cmd" "cmd2" outfile$(RESET)"

bonus: ${BONUS_OBJS}
	@${RM} $(OBJS)
	@$(LIBFT_MAKE)
	@$(LIBFT_CP)
	@$(GCC) $(FLAGS) -o $(NAME) $(BONUS_OBJS) libft.a
	@echo "\n\n"
	@echo "$(YELLOW)now just ./pipex infile "cmd" "cmd2" outfile$(RESET)"

clean:
	@$(RM) $(OBJS)
	@$(RM) $(BONUS_OBJS)

fclean:
	@echo "$(BOLD)$(LIGHT_BLUE)Cleaning all .o files...$(REST)\n"
	@$(RM) $(NAME)
	@make fclean -C libft
	@$(RM) libft.a
	@make clean
	@echo "\n$(BOLD)$(YELLOW)Clean Successfully$(RESET)"

re: fclean all

re_bonus: fclean bonus

files:
	@touch infile
	@touch outfile
	@echo "\n$(BOLD)$(YELLOW)infile and outfile created$(RESET)"

clean_files:
	@echo "$(BOLD)$(LIGHT_BLUE)Cleaning files...$(REST)\n"
	@rm infile
	@rm outfile
	@echo "$(BOLD)$(YELLOW)removed successfully :D$(RESET)"

.PHONY: all clean fclean re files bonus clean_files re_bonus