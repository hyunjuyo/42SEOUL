/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 16:13:49 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/04/22 19:46:37 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "./Libft/libft.h"
# include "get_next_line.h"

# define STACK_SIZE 100
# define INST_COUNT 50
# define OPER_LEN   3
# define NOT_INT    10100100100

typedef struct  s_stack
{
    long long   a[STACK_SIZE];
    long long   b[STACK_SIZE];
    char        inst[INST_COUNT][OPER_LEN + 1];
    int         inst_num;
}               t_stack;

typedef struct  s_atoi_info
{
    int             i;
    int             sign;
    int             check;
    unsigned int    temp;
}               t_atoi_info;

int     atoi_error_check(char *str);
void	print_error(char *message, int type);
void    read_inst(t_stack *stack);
void	error_check_inst(t_stack *stack, int i);
void	exec_inst(t_stack *stack);

#endif