SRCS	=	get_next_line.c get_next_line_utils.c \

SRCS_BONUS	=	Bonus/get_next_line_bonus.c Bonus/get_next_line_utils_bonus.c \

GCC			= gcc
CFLAGS		= -Wall -Werror -Wextra
NAME		= gnl.a
ARRC		= ar rc
RM			= rm -f
OBJS		= $(SRCS:.c=.o)
OBJS_BONUS	= $(SRCS_BONUS:.c=.o)

all: $(NAME)

%.o: %.c
	@$(GCC) -c $(CFLAGS) $< -o ${<:.c=.o}

$(NAME): $(OBJS)
	@$(ARRC) $(NAME) $(OBJS)

bonus: $(OBJS) $(OBJS_BONUS)
	@$(ARRC) $(NAME) $(OBJS_BONUS)

clean:
	@$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

re_bonus: fclean bonus

.PHONY: all clean fclean re bonus re_bonus
