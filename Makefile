# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/01 12:45:22 by vviterbo          #+#    #+#              #
#    Updated: 2024/10/21 14:24:55 by vviterbo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pushswap

SRCS =	push_funcs.c swap_funcs.c main.c print_list.c

OBJS = $(patsubst %.c, %.o, $(SRCS))

HEADER = PushSwap.h libft/libft.h

LIB = libft

CFLAGS = -Wall -Wextra -Werror

CC = cc


all: $(NAME)

clean :
	@rm -f $(OBJS)

fclean : clean
	@rm -f $(NAME)

re : fclean all

$(NAME): 
	@$(MAKE) -C libft/ bonus
	@$(CC) $(CFLAGS) $(SRCS) -o $(NAME) -I $(LIB)/libft.h -L $(LIB) -lft

.PHONY: all clean fclean re bonus