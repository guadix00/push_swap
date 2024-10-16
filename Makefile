# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gualvare <gualvare@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/12 19:19:53 by gualvare          #+#    #+#              #
#    Updated: 2024/10/14 13:30:05 by gualvare         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = src/push_swap.c src/utils.c src/push.c src/swap.c src/rotate.c src/reverse_rotate.c src/check_sort.c src/set_algorithm.c src/algortihm.c src/error_and_free.c src/init_stack.c
OBJS = $(SRCS:.c=.o)

LIBFT_DIR = libft 
LIBFT = $(LIBFT_DIR)/libft.a

INCLUDE = src/push_swap.h \
					libft/libft.h libft/ft_printf.h
CC = cc 
CFLAGS = -Wall -Wextra -Werror -fsanitize=address

END = \033[m
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
PURPLE = \033[35m
CIAN = \033[36m


all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
		$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

$(LIBFT):
	@echo "\n $(YELLOW) === Compiling libft... === $(END)\n"
	@make -C $(LIBFT_DIR)

%.o: %.c $(INCLUDE)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "\n$(YELLOW)--- Cleaning object files...$(END) ---\n"
	@make -C $(LIBFT_DIR) clean
	@rm -f $(OBJS)

fclean: clean
	@echo "\n $(YELLOW)--- Cleaning everything, including the executable...$(END) ---\n"
	@make -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)


.PHONY: all clean fclea
