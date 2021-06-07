# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddelena <ddelena@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/19 17:46:16 by ddelena           #+#    #+#              #
#    Updated: 2021/06/07 15:45:00 by ddelena          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
NAME	= libftprintf.a
HEAD	= libft.h
SRCS	=	ft_putstr_ch.c	ft_putchar_fd.c \
			ft_putnbr_fd.c	\
			ft_flags_count.c	ft_printf.c		ft_type_pars.c \
			ft_flag_pars.c	ft_flags_c.c	treat_width.c	\
			dispars_char.c	dispars_string.c ft_dispars.c \
			print_int.c 	ft_isdigit.c ft_strlen.c


LIBA    = libft/libft.a

OBJS    = ${SRCS:.c=.o}

%.o : %.c   ${HEAD}
			${CC} ${FLAGS} -c $< -o $@

$(NAME): ${OBJS} ${HEAD}
		$(MAKE) -C $(dir $(LIBA))
		mv $(LIBA) $(NAME)
		ar rcs ${NAME} $?

all: ${NAME}

clean:
		rm -f ${OBJS}

fclean:	clean
		rm -f ${NAME} 
re:		fclean all

main:
	gcc -o a.out *.o

.PHONY:	all, clean, fclean, re bonus