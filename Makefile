# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/15 16:49:48 by jjauzion          #+#    #+#              #
#    Updated: 2017/12/18 17:22:30 by jjauzion         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = src/ft_printf.c src/ft_parse.c src/ft_count_specifier.c\
	   main.c

OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

NAME = printf_test

all: $(NAME)

$(NAME): LIB $(OBJS)
	gcc -o $(NAME) -Iincludes includes/libft/libft.a $(FLAGS) $(OBJS)

LIB:
	make -C includes/libft

%.o: %.c
	gcc $(FLAGS) -Iincludes -c -o $@ $<

clean:
		make clean -C includes/libft
			rm -f $(OBJS)

fclean: clean
		make fclean -C includes/libft
			rm -f $(NAME)

re: fclean all
