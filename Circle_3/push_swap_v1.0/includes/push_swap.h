/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 16:13:49 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/04/29 20:23:50 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include "get_next_line.h"

# define STACK_SIZE 1000
# define INST_COUNT 50000
# define OPER_LEN   3
# define EMPTY      10100100100

typedef struct  s_idx
{
    int         a;
    int         b;
}               t_idx;

typedef struct  s_num_info
{
    long long   num;
    int         now;
    int         dest;
}               t_num_info;

typedef struct  s_stack
{
    t_num_info  a[STACK_SIZE];
    t_num_info  b[STACK_SIZE];
    int         a_count;
    int         b_count;
    char        inst[INST_COUNT][OPER_LEN + 1];
    int         inst_count;
    int         debug_opt;
    int         debug_opt2;
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
void	save_now_n_dest_order(t_stack *stack);
void	find_min_oper_for_sort(t_stack *stack);
void	check_n_display_oper(t_stack *stack, int dest_order, t_idx *idx);
int		get_dest_order_idx_a(t_stack *stack, int dest_order);
int		get_dest_order_idx_b(t_stack *stack, int dest_order);
void	check_need_swap_max_n_second(t_stack *stack, int dest_order, int idx);
void	write_n_save_status(char *oper, t_stack *stack);
void	check_n_do_swap(t_stack *stack);
void	check_n_do_ss(t_stack *stack);
int		update_now_order(t_stack *stack, int dest_order);
void	print_stack_status(t_stack *stack);

#endif