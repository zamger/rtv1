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

NAME = RTv1
NAME_L = LIBFT
NAME_H =  rtv1.h
LIB = ./libft/libft.a
FILE_SRCS = main.c \
	rtv1_draw.c \
	rtv1_control.c \
	rtv1_vector_func.c \
	rtv1_sphere.c \
	rtv1_cyl.c \
	rtv1_con_inf.c \
	rtv1_plane.c  \
	rtv1_calc_f1.c \
	rtv1_init_func.c \
	rtv1_addit_func.c \
	rtv1_inters_sh.c  \
	rtv1_inters_fig.c \


FILE_O = $(FILE_SRCS:.c=.o)

OFLAGS	= -Wall -Wextra -Werror -c

FLAGS  = -lmlx -framework OpenGL -framework AppKit

.PHONY: all clean fclean re

OBJ = $(SRC:.c=.o)

all:  $(NAME_L) $(NAME)

$(NAME_L): $(FILE_SRCS:.libft/*.c=.libft/*.o)
	@make -C libft/

$(NAME): $(FILE_O)

	@gcc -O3 $(OFLAGS) $(FILE_SRCS)
	@gcc -o $(NAME) $(FILE_O) $(LIB) $(FLAGS)

clean:
	@/bin/rm -f $(FILE_O)

fclean: clean
	@/bin/rm -f $(NAME)

cleanlib:
	@make clean -C libft/

fcleanlib: cleanlib
	@make fclean -C libft/

re: all

norm:
	@norminette *.c *.h
