# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/16 23:13:57 by hyunjuyo          #+#    #+#              #
#    Updated: 2021/01/17 00:57:32 by hyunjuyo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
CFLAGS	= -Wall -Wextra -Werror
SRCS	= ft_printf.c check_flags_1.c check_flags_2.c check_flags_wp.c \
		  start_printf_c.c start_printf_s.c start_printf_p.c \
		  start_printf_di.c start_printf_u.c start_printf_x.c \
		  ft_printf_utils_1.c ft_printf_utils_2.c
OBJS	= $(SRCS:.c=.o)

%.o	: %.c
	gcc $(CFLAGS) -c $< -o $@ -I.

$(NAME)	: $(OBJS)
	make bonus -C Libft/
	cp Libft/libft.a ./$(NAME)
	ar -rcs $(NAME) $(OBJS)

all : $(NAME)

clean	:
	rm -f $(OBJS)
	make clean -C Libft/

fclean	: clean
	rm -f $(NAME)
	make fclean -C Libft/

re	: fclean all
