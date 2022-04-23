# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyunjuyo <hyunjuyo@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/01 17:00:25 by hyunjuyo          #+#    #+#              #
#    Updated: 2022/02/04 17:32:03 by hyunjuyo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo

CFLAGS	=	-Wall -Wextra -Werror

SRCS	=	main.c utils.c utils2.c control.c others.c

OBJS	= 	$(SRCS:.c=.o)

%.o : %.c
	gcc $(CFLAGS) -c $< -o $@ -I./includes/

$(NAME) : $(OBJS)
	gcc $(OBJS) -o $(NAME)

all : $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
