/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_oper_for_sort.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 16:50:51 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/04/25 19:54:35 by hyunjuyo         ###   ########.fr       */
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
	int	idx_a;
	int	idx_b;
	int	dest_order;

	idx_a = -1;
	idx_b = -1;
	dest_order = stack->a_count;
	while (dest_order > 1)
	{
		if ((idx_a = get_dest_order_idx_a(stack, dest_order)) == -1)
			idx_b = get_dest_order_idx_b(stack, dest_order);
		check_n_display_oper(stack, dest_order, idx_a, idx_b);
		dest_order--;
	}
}
