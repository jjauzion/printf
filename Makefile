# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/15 16:49:48 by jjauzion          #+#    #+#              #
#    Updated: 2017/12/19 20:05:54 by jjauzion         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = src/ft_printf.c src/ft_parse.c src/ft_count_specifier.c src/ft_get_param.c\
	   src/ft_padding.c\
	   main.c

OBJS = $(SRCS:.c=.o)

INCL = -Iincludes -Iincludes/libft

NAME = printf_test

ifdef FLAG
	ifeq ($(FLAG), no)
		FLAGS =
	endif
	ifeq ($(FLAG), debug)
		FLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
	endif
else
	FLAGS = -Wall -Wextra -Werror
endif

all: $(NAME)

$(NAME): LIB $(OBJS)
	gcc -o $(NAME) $(INCL) includes/libft/libft.a $(FLAGS) $(OBJS)

LIB:
	make -C includes/libft

%.o: %.c
	gcc $(FLAGS) $(INCL) -c -o $@ $<

clean:
	make clean -C includes/libft
	rm -f $(OBJS)

fclean: clean
	make fclean -C includes/libft
	rm -f $(NAME)

re: fclean all
