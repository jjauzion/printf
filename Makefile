# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/17 14:43:00 by jjauzion          #+#    #+#              #
#    Updated: 2018/01/17 16:07:41 by jjauzion         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = src/

SRC_NAME = ft_printf.c \
		   ft_parse.c \
		   ft_count_specifier.c \
		   ft_get_param.c \
		   ft_generate_field.c \
		   ft_parse_fct.c \
		   ft_apply_hashtag.c \
		   ft_add_precision.c \
		   ft_field_fct.c \
		   ft_get_arg.c \
		   float_arg.c \
		   ft_padding.c \
		   ft_print_all.c \
		   ft_int_arg.c \
		   ft_uint_arg.c \
		   ft_generate_wfield.c \
		   ft_clean_utf8str.c \
		   char_arg_fct.c \
		   main.c

OBJ_PATH = obj/

LIB_PATH = includes/libft/

INC_PATH = includes/ \
		   includes/libft/

LDLIBS = -lft

NAME = test_printf

CC = gcc

ifdef FLAG
	ifeq ($(FLAG), no)
		CFLAGS =
		DBFLAGS =
	endif
	ifeq ($(FLAG), debug)
		CFLAGS = -Wall -Wextra -Werror
		DBFLAGS = -g3 -fsanitize=address
	endif
else
	CFLAGS = -Wall -Wextra -Werror
	DBFLAGS =
endif

OBJ_NAME = $(SRC_NAME:.c=.o)
SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
LDFLAGS = $(addprefix -L,$(LIB_PATH))
CPPFLAGS = $(addprefix -I,$(INC_PATH))

all: LIB $(NAME)

$(NAME): $(OBJ)
	$(CC) $(DBFLAGS) $(LDFLAGS) $(LDLIBS) $^ -o $@

LIB:
	make -C $(LIB_PATH) 

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) $(DBFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	make clean -C $(LIB_PATH) 
	rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null/ || true

fclean: clean
	make fclean -C $(LIB_PATH) 
	rm -fv $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re, LIB

norme:
	norminette $(SRC)
	norminette $(INC_PATH)
