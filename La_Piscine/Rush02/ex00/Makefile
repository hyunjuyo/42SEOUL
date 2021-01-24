# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyunjuyo <hyunjuyo@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/06 15:14:26 by hyunjuyo          #+#    #+#              #
#    Updated: 2020/12/06 16:51:48 by hyunjuyo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= rush-02
CFLAGS	= -Wall -Wextra -Werror
OBJS	= main.o ft_ntow.o ft_ntow_newdict.o ft_dict_check.o ft_convert_num.o ft_strstr.o ft_write_word.o

all : $(NAME)

$(NAME) : $(OBJS)
	gcc $(CFLAGS) -o $(NAME) $(OBJS)

main.o : ft.h main.c
	gcc $(CFLAGS) -c -o main.o main.c

ft_ntow.o : ft.h ft_ntow.c
	gcc $(CFLAGS) -c -o ft_ntow.o ft_ntow.c

ft_ntow_newdict.o : ft.h ft_ntow_newdict.c
	gcc $(CFLAGS) -c -o ft_ntow_newdict.o ft_ntow_newdict.c

ft_dict_check.o : ft.h ft_dict_check.c
	gcc $(CFLAGS) -c -o ft_dict_check.o ft_dict_check.c

ft_convert_num.o : ft.h ft_convert_num.c
	gcc $(CFLAGS) -c -o ft_convert_num.o ft_convert_num.c

ft_strstr.o : ft.h ft_strstr.c
	gcc $(CFLAGS) -c -o ft_strstr.o ft_strstr.c

ft_write_word.o : ft.h ft_write_word.c
	gcc $(CFLAGS) -c -o ft_write_word.o ft_write_word.c

clean :
	rm -f $(OBJS)

fclean :
	rm -f $(OBJS) $(NAME)
