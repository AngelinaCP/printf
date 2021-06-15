# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddelena <ddelena@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/19 17:46:16 by ddelena           #+#    #+#              #
#    Updated: 2021/06/11 18:39:17 by ddelena          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
HEADER	= libftprintf.h
SRCS	=	ft_putstr_ch.c	ft_putchar_fd.c \
			ft_putnbr_fd.c	\
			ft_flags_count.c	ft_printf.c		ft_type_pars.c \
			ft_flag_pars.c	ft_flags_c.c	treat_width.c	\
			dispars_char.c	dispars_string.c ft_dispars.c \
			print_int.c 	ft_isdigit.c ft_strlen.c

OBJS			= $(SRCS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.

all:			$(NAME)

bonus: all

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS) $(HEADER)

clean:
				$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY: clean fclean all re