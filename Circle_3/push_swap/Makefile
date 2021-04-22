# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyunjuyo <hyunjuyo@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/21 15:44:48 by hyunjuyo          #+#    #+#              #
#    Updated: 2021/04/22 16:23:42 by hyunjuyo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1	= checker
NAME2	= push_swap

CFLAGS	= -Wall -Wextra -Werror
LIBFT_FLAGS	= -L./Libft -lft

CHECKER_SRCS	=
PUSH_SWAP_SRCS	=

CHECKER_OBJS	= $(CHECKER_SRCS:.c=.o)
PUSH_SWAP_OBJS	= $(PUSH_SWAP_SRCS:.c=.o)

%.o : %.c
	gcc $(CFLAGS) -c $< -o $@ -I.

$(NAME1) : $(CHECKER_OBJS)
	make bonus -C ./Libft/
	gcc $(CHECKER_OBJS) $(LIBFT_FLAGS) -o $(NAME1)

$(NAME2) : $(PUSH_SWAP_OBJS)
	make bonus -C ./Libft/
	gcc $(PUSH_SWAP_OBJS) $(LIBFT_FLAGS) -o $(NAME2)

all : $(NAME1) $(NAME2)

clean :
	rm -f $(CHECKER_OBJS) $(PUSH_SWAP_OBJS)
	make clean -C ./Libft/

fclean : clean
	rm -f $(NAME1) $(NAME2)
	make fclean -C ./Libft/

re : fclean all
