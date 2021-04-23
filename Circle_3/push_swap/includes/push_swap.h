/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 16:13:49 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/04/23 15:26:05 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include "get_next_line.h"

# define STACK_SIZE 100
# define INST_COUNT 50
# define OPER_LEN   3
# define NOT_INT    10100100100

typedef struct  s_stack
{
    long long   a[STACK_SIZE];
    long long   b[STACK_SIZE];
    int         a_count;
    int         b_count;
    char        inst[INST_COUNT][OPER_LEN + 1];
    int         inst_count;
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
void	operations_sa(t_stack *stack);
void	operations_sb(t_stack *stack);
void	operations_ss(t_stack *stack);
void	operations_pa(t_stack *stack);
void	operations_pb(t_stack *stack);
void	operations_ra(t_stack *stack);
void	operations_rb(t_stack *stack);
void	operations_rr(t_stack *stack);
void	operations_rra(t_stack *stack);
void	operations_rrb(t_stack *stack);
void	operations_rrr(t_stack *stack);
void    check_stack_sorted(t_stack *stack);

#endif