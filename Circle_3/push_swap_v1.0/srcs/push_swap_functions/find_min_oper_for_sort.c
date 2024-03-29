/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_oper_for_sort.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 16:50:51 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/04/29 20:38:40 by hyunjuyo         ###   ########.fr       */
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

	if (stack->a_count + stack->b_count <= 30)
		scale = 10;
	else if (stack->a_count + stack->b_count <= 100)
		scale = 15;
	else if (stack->a_count + stack->b_count <= 200)
		scale = 30;
	else
		scale = 45;
	return (scale);
}

void	grouping_numbers(t_stack *stack)
{
	int	scale;
	int	i;
	int	j;
	int	count;

	scale = choose_scale(stack);
	i = 1;
	while (scale * i < stack->a_count + stack->b_count)
	{
		count = stack->a_count;
//		printf("scale * i : %d, count : %d\n", scale * i, count); //test
		j = -1;
		while (++j < count)
		{
			if (stack->a[0].dest <= scale * i)
			{
				write_n_save_status("pb", stack);
//				if (stack->b[1].num != EMPTY && stack->b[0].num < stack->b[1].num)
//				{
//					if (stack->b[0].num > stack->b[2].num)
//					{
//						if (stack->a[0].num > stack->a[1].num)
//							write_n_save_status("ss", stack);
//						else
//							write_n_save_status("sb", stack);
//					}
//				}
			}
			else
				write_n_save_status("ra", stack);
			if (stack->b_count == scale * i)
				break ;
		}
		i++;
	}
//	printf("==================== total_count : %d, scale * i : %d \"Grouping complete\" ====================\n", stack->a_count + stack->b_count, scale * i); //test
}

void	find_min_oper_for_sort(t_stack *stack)
{
	t_idx	idx;
	int		dest_order;
//	int		i; //test

	if (stack->a_count >= 20)
		grouping_numbers(stack);
	save_now_n_dest_order(stack);
//	i = -1; //test
//	while (++i < stack->a_count) //test
//		printf("[a] %lld,\tnow : %d, dest : %d\n",stack->a[i].num, stack->a[i].now, stack->a[i].dest); //test
//	i = -1; //test
//	while (++i < stack->b_count) //test
//		printf("[b] %lld,\tnow : %d, dest : %d\n",stack->b[i].num, stack->b[i].now, stack->b[i].dest); //test
	idx.a = -1;
	idx.b = -1;
	dest_order = stack->a_count + stack->b_count;
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
