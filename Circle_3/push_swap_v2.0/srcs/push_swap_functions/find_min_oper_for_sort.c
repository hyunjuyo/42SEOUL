/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_oper_for_sort.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 16:50:51 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/05/02 16:59:42 by hyunjuyo         ###   ########.fr       */
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

int		choose_scale(t_stack *stack)
{
	int	scale;

	if (stack->a_count + stack->b_count <= 50)
		scale = 21;
	else if (stack->a_count + stack->b_count <= 150)
		scale = 31;
	else if (stack->a_count + stack->b_count <= 300)
		scale = 39;
	else
		scale = 70;
	return (scale);
}

void	grouping_numbers(t_stack *stack)
{
	int	scale;
	int	i;
	int	j;
	int	count;

	scale = choose_scale(stack);
	i = 0;
	while (scale * (++i) < stack->a_count + stack->b_count)
	{
		count = stack->a_count;
		j = -1;
		while (++j < count)
		{
			if (stack->a[0].dest <= scale * i)
			{
				write_n_save_status("pb", stack);
				sub_grouping_numbers_step1(stack, scale, i);
			}
			else
				write_n_save_status("ra", stack);
			if (stack->b_count == scale * i)
				break ;
		}
		sub_grouping_numbers_step2(stack, scale, i);
	}
}

void	find_min_oper_for_sort(t_stack *stack)
{
	t_idx	idx;
	int		dest_order;

	if (stack->a_count >= 20)
		grouping_numbers(stack);
	save_now_n_dest_order(stack);
	idx.a = -1;
	idx.b = -1;
	dest_order = stack->a_count + stack->b_count;
	while (dest_order > 1)
	{
		idx.a = get_dest_order_idx_a(stack, dest_order);
		if (idx.a == -1)
			idx.b = get_dest_order_idx_b(stack, dest_order);
		check_n_display_oper(stack, dest_order, &idx);
		dest_order--;
	}
}
