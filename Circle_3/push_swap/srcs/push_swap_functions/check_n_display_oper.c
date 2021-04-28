/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_n_display_oper.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 17:36:03 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/04/28 16:44:22 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	consider_already_pb_n_move(t_stack *stack, int count_num, int now_order)
{
    int i;

	i = 0 + stack->b_count; //consider already "pb"
	while (i < count_num)
    {
		write_n_save_status("pb", stack);
		if (now_order > (stack->a_count + stack->b_count) / 2)
			check_n_do_ss(stack);
        i++;
    }
	if (i > count_num) //consider already "pb"
	{
		while (i > count_num)
		{
			write_n_save_status("pa", stack);
			check_n_do_ss(stack);
			i--;
		}
	}
}

void	check_n_do_swap(t_stack *stack)
{
	if (stack->b[0].num < stack->b[1].num)
		write_n_save_status("ss", stack);
	else
		write_n_save_status("sa", stack);
}

void	check_n_display_oper_3(t_stack *stack, int dest_order, int now_order)
{
	int	i;

	i = -1;
	if (now_order < dest_order - 1)
	{
		consider_already_pb_n_move(stack, dest_order, now_order);
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
	else if (now_order == dest_order - 1)
	{
		consider_already_pb_n_move(stack, now_order - 1, now_order);
		now_order = update_now_order(stack, dest_order);
		if (now_order == dest_order - 1)
			check_n_do_swap(stack);
	}
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
//	printf("now_order : %d, stack->b_count : %d\n", now_order, stack->b_count); //test
	if (dest_order == 2)
	{
		count = stack->b_count;
		i = -1;
		while (++i < count)
			write_n_save_status("pa", stack);
		if (now_order == 1)
			write_n_save_status("sa", stack);
	}
	else
		check_n_display_oper_3(stack, dest_order, now_order);
}

void	check_n_display_oper(t_stack *stack, int dest_order, t_idx *idx)
{
	int	i;

//	printf("dest_order : %d, idx : (%d, %d)\n", dest_order, idx->a, idx->b); //test
	if (dest_order == stack->a_count + stack->b_count)
	{
		check_need_swap_max_n_second(stack, dest_order, idx->a);
		idx->a = get_dest_order_idx_a(stack, dest_order);
		printf("stack->a[%d].now : %d, stack->b_count : %d\n", idx->a, stack->a[idx->a].now, stack->b_count); //test
		if (stack->a[idx->a].now - stack->b_count > stack->a_count / 2)
		{
			i = -1;
			while (++i < stack->a_count - (stack->a[idx->a].now - stack->b_count))
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
