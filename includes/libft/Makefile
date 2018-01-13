# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 10:02:24 by jjauzion          #+#    #+#              #
#    Updated: 2018/01/13 20:12:53 by jjauzion         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Werror -Wall -Wextra
SRCS = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c\
	   ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c ft_atoi.c ft_putchar.c ft_putnbr.c\
	   ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_strcmp.c\
	   ft_strncmp.c ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c\
	   ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_strext.c\
	   ft_itoa.c ft_strrev.c ft_putstr.c ft_putendl.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
	   ft_memmove.c ft_memchr.c ft_memcmp.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c\
	   ft_islower.c ft_isupper.c ft_strcapitalize.c ft_strcnew.c ft_sqrt.c ft_uitoa.c ft_realloc.c ft_dtoa.c\
	   ft_round_up.c ft_power.c ft_uitoa_base.c ft_strremap.c ft_strremapi.c ft_count_cinstr.c ft_str_del_char.c\
	   ft_putwchar.c ft_putwstr.c ft_strnchr.c ft_ishexa.c ft_wstrcnew.c ft_wstrlen.c ft_wstrsub.c ft_wstrdup.c\
	   ft_getnbofutf8byte.c ft_wstr2str.c ft_uni2utf8.c\

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
