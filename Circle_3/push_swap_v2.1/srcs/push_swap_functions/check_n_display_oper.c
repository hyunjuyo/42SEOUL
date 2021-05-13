/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_n_display_oper.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 17:36:03 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/05/13 13:51:18 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	consider_pb_n_move(t_stack *stack, int count_num, int now_order)
{
	int	i;

	i = 0 + stack->b_count;
	while (i < count_num)
	{
		write_n_save_status("pb", stack);
		if (now_order > (stack->a_count + stack->b_count) / 2)
			check_n_do_ss(stack);
		i++;
	}
	if (i > count_num)
	{
		while (i > count_num)
		{
			write_n_save_status("pa", stack);
			check_n_do_ss(stack);
			i--;
		}
	}
}

void	check_n_display_oper_4(t_stack *stack, int dest_order, int now_order)
{
	int	count;

	if (now_order == dest_order - 1 && now_order < stack->b_count)
	{
		count = stack->b_count - 1;
		while (now_order < count)
		{
			write_n_save_status("pa", stack);
			now_order++;
		}
		write_n_save_status("sb", stack);
	}
	else if (now_order == dest_order - 1)
	{
		consider_pb_n_move(stack, now_order - 1, now_order);
		now_order = update_now_order(stack, dest_order);
		if (now_order == dest_order - 1)
			check_n_do_swap(stack);
	}
}

void	check_n_display_oper_3(t_stack *stack, int dest_order, int now_order)
{
	int	i;

	i = -1;
	if (now_order < dest_order - 1)
	{
		consider_pb_n_move(stack, dest_order, now_order);
		now_order = update_now_order(stack, dest_order);
		if (now_order > dest_order / 2)
		{
			while (++i < dest_order - now_order)
				write_n_save_status("rb", stack);
		}
		else
		{
			while (++i < now_order)
				write_n_save_status("rrb", stack);
		}
	}
	else
		check_n_display_oper_4(stack, dest_order, now_order);
}

void	check_n_display_oper_2(t_stack *stack, int dest_order, t_idx *idx)
{
	int	i;
	int	now_order;
	int	count;

	if (idx->a > -1)
		now_order = stack->a[idx->a].now;
	else
		now_order = stack->b[idx->b].now;
	if (dest_order == 2)
	{
		count = stack->b_count;
		i = -1;
		while (++i < count)
		{
			if (i == count - 1 && now_order == 2)
				stack->set_color = 1;
			write_n_save_status("pa", stack);
		}
		if (now_order == 1)
		{
			stack->set_color = 1;
			write_n_save_status("sa", stack);
		}
	}
	else
		check_n_display_oper_3(stack, dest_order, now_order);
}

void	check_n_display_oper(t_stack *stack, int dest_order, t_idx *idx)
{
	int	i;
	int	idx2;

	if (dest_order == stack->a_count + stack->b_count)
	{
		idx2 = get_dest_order_idx_a(stack, dest_order - 1);
		if (!(dest_order == stack->a[idx->a].now && stack->a[idx2].now < 3))
			check_need_swap_max_n_second(stack, dest_order, idx->a);
		idx->a = get_dest_order_idx_a(stack, dest_order);
		if (stack->a[idx->a].now - stack->b_count > stack->a_count / 2)
		{
			i = -1;
			while (++i < stack->a_count -
					(stack->a[idx->a].now - stack->b_count))
				write_n_save_status("rra", stack);
		}
		else
		{
			i = -1;
			while (++i < stack->a[idx->a].now - stack->b_count)
				write_n_save_status("ra", stack);
		}
	}
	else
		check_n_display_oper_2(stack, dest_order, idx);
}
