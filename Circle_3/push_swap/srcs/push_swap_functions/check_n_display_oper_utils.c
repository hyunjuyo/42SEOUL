/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_n_display_oper_utils.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 15:44:48 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/04/28 15:31:27 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		update_now_order(t_stack *stack, int dest_order)
{
	t_idx	temp;
	int		now_order;

	temp.a = get_dest_order_idx_a(stack, dest_order);
	if (temp.a == -1)
		temp.b = get_dest_order_idx_b(stack, dest_order);
	if (temp.a > -1)
		now_order = stack->a[temp.a].now;
	else
		now_order = stack->b[temp.b].now;
	return (now_order);
}

void	check_n_do_ss(t_stack *stack)
{
	if (stack->a[0].num > stack->a[1].num && stack->b[0].num < stack->b[1].num)
	{
		write(1, "ss\n", 3);
		operations_ss(stack);
		if (stack->debug_opt == 1)
			print_stack_status(stack);
	}
}

void    do_swap_max_n_second(t_stack *stack, int max_now)
{
    int i;

	if ((max_now - stack->b_count) - 1 > stack->a_count / 2)
	{
		i = -1;
		while (++i < stack->a_count - (max_now - stack->b_count) + 1)
			write_n_save_status("rra", stack);
	}
	else
	{
		i = -1;
		while (++i < (max_now - stack->b_count) - 1)
			write_n_save_status("ra", stack);
	}
	write_n_save_status("sa", stack);
}

void	check_need_swap_max_n_second(t_stack *stack, int dest_order, int idx)
{
	t_idx	sec;
	int		max_now;
	int		sec_now;
	int		temp;

	sec.a = get_dest_order_idx_a(stack, dest_order - 1);
	printf("idx : %d, sec.a : %d\n", idx, sec.a); //test
	max_now = stack->a[idx].now;
	sec_now = stack->a[sec.a].now;
	printf("max_now : %d, sec_now : %d\n", max_now, sec_now); //test
	if ((temp = max_now + 1) > stack->a_count + stack->b_count)
		temp -= stack->a_count;
	printf("sec_now : %d, temp : %d\n", sec_now, temp); //test
	if (sec_now == temp)
		do_swap_max_n_second(stack, max_now);
}
