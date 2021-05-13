# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyunjuyo <hyunjuyo@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/21 15:44:48 by hyunjuyo          #+#    #+#              #
#    Updated: 2021/05/13 17:17:10 by hyunjuyo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
CHECKER	= checker

CFLAGS	= -Wall -Wextra -Werror
LIBFT_FLAGS	= -L./Libft -lft

CHECKER_SRCS	= ./srcs/main_checker.c ./srcs/utils/atoi_error_check.c \
				  ./srcs/utils/utils.c ./srcs/utils/get_next_line.c \
				  ./srcs/checker_functions/read_n_exec_inst.c \
				  ./srcs/operations/operations_s_p.c \
				  ./srcs/operations/operations_r.c \
				  ./srcs/operations/operations_rr.c \
				  ./srcs/checker_functions/check_stack_sorted.c
PUSH_SWAP_SRCS	= ./srcs/main_push_swap.c ./srcs/utils/atoi_error_check.c \
				  ./srcs/utils/utils.c \
				  ./srcs/push_swap_functions/save_now_n_dest_order.c \
				  ./srcs/push_swap_functions/find_min_oper_for_sort.c \
				  ./srcs/push_swap_functions/find_min_oper_for_sort_utils.c \
				  ./srcs/push_swap_functions/check_n_display_oper.c \
				  ./srcs/push_swap_functions/check_n_display_oper_utils.c \
				  ./srcs/push_swap_functions/check_n_display_oper_utils2.c \
				  ./srcs/push_swap_functions/write_n_save_status.c \
				  ./srcs/operations/operations_s_p.c \
				  ./srcs/operations/operations_r.c \
				  ./srcs/operations/operations_rr.c

CHECKER_OBJS	= $(CHECKER_SRCS:.c=.o)
PUSH_SWAP_OBJS	= $(PUSH_SWAP_SRCS:.c=.o)

%.o : %.c
	gcc $(CFLAGS) -c $< -o $@ -I./includes/ -I./Libft/

$(NAME) : $(CHECKER_OBJS) $(PUSH_SWAP_OBJS)
	make bonus -C ./Libft/
	gcc $(CHECKER_OBJS) $(LIBFT_FLAGS) -o $(CHECKER)
	gcc $(PUSH_SWAP_OBJS) $(LIBFT_FLAGS) -o $(NAME)

all : $(NAME)

clean :
	make clean -C ./Libft/
	rm -f $(CHECKER_OBJS) $(PUSH_SWAP_OBJS)

fclean : clean
	rm -f $(CHECKER) $(NAME)

re : fclean all
