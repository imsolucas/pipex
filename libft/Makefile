# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: djin <djin@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/09 13:08:20 by djin              #+#    #+#              #
#    Updated: 2023/08/09 18:20:48 by djin             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_MAIN	 =	ft_atoi.c ft_bzero.c ft_isalnum.c \
				ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
				ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c\
				ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
				ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c \
				ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
				ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c \
		

SRCS_BONUS	=	ft_lstdelone.c ft_lstiter.c ft_lstmap.c \
				ft_lstnew.c ft_lstadd_back.c ft_lstadd_front.c \
				ft_lstclear.c ft_lstsize.c ft_lstlast.c \

GCC			= gcc
CFLAGS		= -Wall -Werror -Wextra
NAME		= libft.a
ARRC		= ar rc
RM			= rm -f
OBJS_MAIN	= $(SRCS_MAIN:.c=.o)
OBJS_BONUS	= $(SRCS_BONUS:.c=.o)

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

$(NAME): $(OBJS_MAIN)
	@$(ARRC) $(NAME) $(OBJS_MAIN)

bonus: $(OBJS_MAIN) $(OBJS_BONUS)
	@$(ARRC) $(NAME) $(OBJS_BONUS)

clean:
	@$(RM) $(OBJS_MAIN) $(OBJS_BONUS)

fclean: clean
	@$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean re bonus fclean
