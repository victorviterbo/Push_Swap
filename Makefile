# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/01 12:45:22 by vviterbo          #+#    #+#              #
#    Updated: 2024/11/03 17:04:32 by vviterbo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS =	push.c swap.c main.c rotate.c revrotate.c utils.c simplify.c exit.c print.c

OBJS = $(patsubst %.c, %.o, $(SRCS))

LIB = libft/

CFLAGS = -Wall -Wextra -Werror

CC = cc

all: $(NAME)

clean :
	@rm -f $(OBJS)

fclean : clean
	@rm -f $(NAME)

re : fclean all

$(NAME): 
	@$(MAKE) -C libft/ xtra
	@$(CC) $(CFLAGS) $(SRCS) -o $(NAME) -I $(LIB)/libft.h -L $(LIB) -lft

bonus : all
	@$(MAKE) bonus/ all

.PHONY: all clean fclean re bonus
