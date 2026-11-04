# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alavryk <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/04 17:08:19 by alavryk           #+#    #+#              #
#    Updated: 2026/11/04 17:08:23 by alavryk          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = push_swap
BONUS_NAME  = checker

CC          = gcc
CFLAGS      = -Wall -Werror -Wextra -Iincludes

SRCS_MAND   = srcs/mandatory/main.c \
              srcs/mandatory/parsing.c \
              srcs/mandatory/stack_utils.c \
              srcs/mandatory/disorder.c \
              srcs/mandatory/ops_swap.c \
              srcs/mandatory/ops_push.c \
              srcs/mandatory/ops_rotate.c \
              srcs/mandatory/ops_reverse_rotate.c \
              srcs/mandatory/algo_simple.c \
              srcs/mandatory/algo_medium.c \
              srcs/mandatory/algo_complex.c \
              srcs/mandatory/algo_adaptive.c \
              srcs/mandatory/bench.c

SRCS_BONUS  = srcs/bonus/checker_bonus.c \
              srcs/mandatory/parsing.c \
              srcs/mandatory/stack_utils.c \
              srcs/mandatory/disorder.c \
              srcs/mandatory/ops_swap.c \
              srcs/mandatory/ops_push.c \
              srcs/mandatory/ops_rotate.c \
              srcs/mandatory/ops_reverse_rotate.c \
              srcs/mandatory/bench.c

OBJS_MAND   = $(SRCS_MAND:.c=.o)
OBJS_BONUS  = $(SRCS_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS_MAND)
	$(CC) $(CFLAGS) $(OBJS_MAND) -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(OBJS_BONUS) -o $(BONUS_NAME)

clean:
	rm -f $(OBJS_MAND) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus
