/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_n_display_oper_utils.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 15:44:48 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/04/27 17:31:47 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    do_swap_max_n_second(t_stack *stack, int max_now)
{
    int i;

	if (max_now - 1 > stack->a_count / 2)
	{
		i = -1;
		while (++i < stack->a_count - max_now + 1)
			write_n_save_status("rra", stack);
	}
	else
	{
		i = -1;
		while (++i < max_now - 1)
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
	max_now = stack->a[idx].now;
	sec_now = stack->a[sec.a].now;
	if ((temp = max_now + 1) > stack->a_count)
		temp -= stack->a_count;
	if (sec_now == temp)
        do_swap_max_n_second(stack, max_now);
}
