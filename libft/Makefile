#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akryvenk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/13 11:21:19 by akryvenk          #+#    #+#              #
#    Updated: 2016/09/15 19:33:49 by akryvenk         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a
NAME_H =  -I libft.h
FILE_SRCS = ft_isalnum.c \
ft_atoi.c \
ft_bzero.c \
ft_isalpha.c \
ft_isascii.c \
ft_isdigit.c \
ft_isprint.c \
ft_memalloc.c \
ft_memchr.c \
ft_memccpy.c \
ft_memcmp.c \
ft_memcpy.c \
ft_memdel.c \
ft_memmove.c \
ft_memset.c \
ft_putchar.c \
ft_putstr.c \
ft_strcat.c \
ft_strchr.c \
ft_strclr.c \
ft_strcmp.c \
ft_strcpy.c \
ft_strdel.c \
ft_strdup.c \
ft_strlcat.c \
ft_strlen.c \
ft_strncat.c \
ft_strncmp.c \
ft_strncpy.c \
ft_strnew.c \
ft_strnstr.c \
ft_strrchr.c \
ft_strstr.c \
ft_tolower.c \
ft_toupper.c \
ft_putnbr.c \
ft_putendl.c \
ft_putchar_fd.c \
ft_putstr_fd.c \
ft_putnbr_fd.c \
ft_putendl_fd.c \
ft_striter.c  \
ft_striteri.c \
ft_strmapi.c \
ft_strequ.c \
ft_strnequ.c \
ft_strsub.c \
ft_strjoin.c \
ft_strtrim.c \
ft_lstnew.c \
ft_lstdelone.c \
ft_lstdel.c \
ft_lstadd.c \
ft_lstiter.c \
ft_strsplit.c \
ft_strmap.c \
ft_lstmap.c \
ft_itoa.c \
ft_print_file.c \
ft_isspace.c \
ft_memclr.c \
ft_strrev.c \
ft_lstpush_back.c \
ft_lstget_node.c 

FILE_O = ft_isalnum.o \
ft_atoi.o \
ft_bzero.o \
ft_isalpha.o \
ft_isascii.o \
ft_isdigit.o \
ft_isprint.o \
ft_memalloc.o \
ft_memchr.o \
ft_memccpy.o \
ft_memcmp.o \
ft_memcpy.o \
ft_memdel.o \
ft_memmove.o \
ft_memset.o \
ft_putchar.o \
ft_putstr.o \
ft_strcat.o \
ft_strchr.o \
ft_strclr.o \
ft_strcmp.o \
ft_strcpy.o \
ft_strdel.o \
ft_strdup.o \
ft_strlcat.o \
ft_strlen.o \
ft_strncat.o \
ft_strncmp.o \
ft_strncpy.o \
ft_strnew.o \
ft_strnstr.o \
ft_strrchr.o \
ft_strstr.o \
ft_tolower.o \
ft_toupper.o \
ft_putnbr.o \
ft_putendl.o \
ft_putchar_fd.o \
ft_putstr_fd.o \
ft_putnbr_fd.o \
ft_putendl_fd.o \
ft_striter.o \
ft_striteri.o \
ft_strmapi.o \
ft_strequ.o \
ft_strnequ.o \
ft_strsub.o \
ft_strjoin.o \
ft_strtrim.o \
ft_lstnew.o \
ft_lstdelone.o \
ft_lstdel.o \
ft_lstadd.o \
ft_lstiter.o \
ft_strsplit.o \
ft_strmap.o \
ft_lstmap.o \
ft_itoa.o \
ft_print_file.o \
ft_isspace.o \
ft_memclr.o \
ft_strrev.o \
ft_lstpush_back.o \
ft_lstget_node.o 

FLAGS	= -Wall -Werror -Wextra

.PHONY: all clean fclean re

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(FILE_O)
	@ar -cru $(NAME) $(FILE_O)
	@ranlib $(NAME)

%.o: %.c libft.h
	@gcc -c $(FLAGS) -c -o $@ $<

clean:
	@/bin/rm -f $(FILE_O)

fclean: clean
	@/bin/rm -f $(NAME)

re: all

norm:
	@norminette ft_*.c libft.h