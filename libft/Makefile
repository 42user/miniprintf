# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/13 14:39:44 by user              #+#    #+#              #
#    Updated: 2020/11/26 08:18:25 by fharissa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

#** Part 1 - Libc function **#

SRC =\
	ft_memset.c\
	ft_bzero.c\
    ft_memcpy.c\
    ft_memccpy.c\
    ft_memmove.c\
    ft_memchr.c\
    ft_memcmp.c\
    ft_strlen.c\
	ft_strlcpy.c\
    ft_strlcat.c\
    ft_strchr.c\
    ft_strrchr.c\
    ft_strnstr.c\
    ft_strncmp.c\
    ft_atoi.c\
    ft_isalpha.c\
    ft_isdigit.c\
    ft_isalnum.c\
    ft_isascii.c\
    ft_isprint.c\
    ft_toupper.c\
    ft_tolower.c\
    ft_calloc.c\
    ft_strdup.c\

#** Part 2 - Add functions **#

SRC +=\
	ft_substr.c\
    ft_strjoin.c\
	ft_split.c\
	ft_strtrim.c\
	ft_itoa.c\
    ft_strmapi.c\
    ft_putchar_fd.c\
    ft_putstr_fd.c\
    ft_putendl_fd.c\
    ft_putnbr_fd.c\

#******* Bonus part ********#

#SRC +=\
#      ft_lstnew.c\

OBJ = $(SRC:.c=.o)
CC = gcc 
#INC = includes/
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	ar -rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: libft.a, all, clean, fclean, re, bonus
