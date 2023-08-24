NAME = pipex
DNAME = d.out
GCC = gcc
FLAGS = -Wall -Wextra -Werror -ggdb -fsanitize=address
DFLAGS = -g3 -fsanitize=address

SRCS = Mandatory/pipex.c Mandatory/pipex_utils.c Mandatory/execution.c
BONUS_SRCS = Bonus/pipex_bonus.c Bonus/pipex_bonus_utils.c Bonus/exec.c Bonus/here_doc.c Bonus/linked_lst_utils.c
BONUS_OBJS	= $(BONUS_SRCS:.c=.o)
OBJS = $(SRCS:.c=.o)

LIBFT_MAKE = make all -C libft
LIBFT_CP = cp libft/libft.a .

GNL_MAKE = make all -C GetNextLine
GNL_CP = cp GetNextLine/gnl.a .

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

d: $(DNAME)

%.o: %.c
	@$(GCC) -c $(CFLAGS) $< -o ${<:.c=.o}

$(NAME): $(OBJS)
	@${RM} $(BONUS_OBJS)
	@$(LIBFT_MAKE)
	@$(LIBFT_CP)
	@$(GCC) $(FLAGS) -o $(NAME) $(OBJS) libft.a
	@echo "\n\n"
	@echo "$(YELLOW)now just ./pipex infile "cmd" "cmd2" outfile$(RESET)"

$(DNAME): $(SRCS)
	@${RM} $(BONUS_OBJS)
	@$(LIBFT_MAKE)
	@$(LIBFT_CP)
	@$(GCC) $(FLAGS) $(DFLAGS) -o $(DNAME) $(SRCS) libft.a
	@echo "\n\n"
	@echo "$(YELLOW)now just ./pipex infile "cmd" "cmd2" outfile$(RESET)"

bonus: ${BONUS_OBJS}
	@${RM} $(OBJS)
	@$(LIBFT_MAKE)
	@$(LIBFT_CP)
	@$(GNL_MAKE)
	@$(GNL_CP)
	@$(GCC) $(FLAGS) -g -o $(NAME) $(BONUS_OBJS) libft.a gnl.a
	@echo "\n\n"
	@echo "$(YELLOW)now just ./pipex infile "cmd" "cmd2" outfile$(RESET)"

clean:
	$(RM) $(OBJS) $(BONUS_OBJS) libft.a gnl.a
	@make fclean -C libft
	@make fclean -C GetNextLine

fclean:
	@echo "$(BOLD)$(LIGHT_BLUE)Cleaning all .o files...$(REST)\n"
	@$(RM) $(NAME)
	@$(RM) $(DNAME)
	@make fclean -C libft
	@make fclean -C GetNextLine
	@$(RM) libft.a
	@make clean
	@echo "\n$(BOLD)$(YELLOW)Clean Successfully$(RESET)"

re: fclean all

re_bonus: fclean bonus

re_d: fclean d

files:
	@touch infile
	@touch outfile
	@echo "\n$(BOLD)$(YELLOW)infile and outfile created$(RESET)"

clean_files:
	@echo "$(BOLD)$(LIGHT_BLUE)Cleaning files...$(REST)\n"
	@rm infile
	@rm outfile
	@echo "$(BOLD)$(YELLOW)removed successfully :D$(RESET)"

.PHONY: all clean fclean re files bonus clean_files re_bonus re_d d