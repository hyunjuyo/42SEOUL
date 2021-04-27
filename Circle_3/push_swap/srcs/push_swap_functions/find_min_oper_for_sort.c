/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_oper_for_sort.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 16:50:51 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/04/27 18:08:01 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_dest_order_idx_a(t_stack *stack, int dest_order)
{
	int	idx;

	idx = 0;
	while (idx < stack->a_count)
	{
		if (stack->a[idx].dest == dest_order)
			return (idx);
		idx++;
	}
	return (-1);
}

int		get_dest_order_idx_b(t_stack *stack, int dest_order)
{
	int	idx;

	idx = 0;
	while (idx < stack->b_count)
	{
		if (stack->b[idx].dest == dest_order)
			return (idx);
		idx++;
	}
	return (-1);
}

void	find_min_oper_for_sort(t_stack *stack)
{
	t_idx	idx;
	int		dest_order;
//	int		i; //test

	idx.a = -1;
	idx.b = -1;
	dest_order = stack->a_count;
	while (dest_order > 1)
	{
		idx.a = get_dest_order_idx_a(stack, dest_order);
		if (idx.a == -1)
			idx.b = get_dest_order_idx_b(stack, dest_order);
		check_n_display_oper(stack, dest_order, &idx);
//		i = -1; //test
//		while (++i < stack->b_count) //test
//			printf("[b] %lld,\tnow : %d, dest : %d\n",stack->b[i].num, stack->b[i].now, stack->b[i].dest); //test
		dest_order--;
	}
}
