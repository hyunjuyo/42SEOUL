/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_n_display_oper.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 17:36:03 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/04/27 14:07:51 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_n_display_oper_2(t_stack *stack, int dest_order, t_idx *idx)
{
	int	i;
	int	now_order;

	if (idx->a > -1)
		now_order = stack->a[idx->a].now;
	else
		now_order = stack->b[idx->b].now;
//	printf("now_order : %d\n", now_order); //test
	if (dest_order == 2)
	{
		i = -1;
		while (++i < stack->b_count)
			write_n_save_status("pa", stack);
		if (now_order == 1)
			write_n_save_status("sa", stack);
	}
	else
	{
		if (now_order < dest_order - 1)
		{
			i = 0 + stack->b_count; //consider already "pb"
			while (i < dest_order)
			{
				write_n_save_status("pb", stack);
				i++;
			}
			if (i > dest_order) //consider already "pb"
			{
				while (i > dest_order)
				{
					write_n_save_status("pa", stack);
					i--;
				}
			}
			if (now_order > dest_order / 2)
			{
				i = -1;
				while (++i < dest_order - now_order)
					write_n_save_status("rb", stack);
			}
			else
			{
				i = -1;
				while (++i < now_order)
					write_n_save_status("rrb", stack);
			}
	
		}
		else if (now_order == dest_order - 1)
		{
			i = 0 + stack->b_count; //consider already "pb"
			while (i < now_order - 1)
			{
				write_n_save_status("pb", stack);
				i++;
			}
			if (i > now_order - 1) //consider already "pb"
			{
				while (i > now_order - 1)
				{
					write_n_save_status("pa", stack);
					i--;
				}
			}
			write_n_save_status("sa", stack);
		}
		else
			return ;
	}
}

void	check_n_display_oper(t_stack *stack, int dest_order, t_idx *idx)
{
	int	i;

//	printf("dest_order : %d, idx : (%d, %d)\n", dest_order, idx->a, idx->b); //test
	if (dest_order == stack->a_count + stack->b_count)
	{
		if (stack->a[idx->a].now > stack->a_count / 2)
		{
			i = -1;
			while (++i < stack->a_count - stack->a[idx->a].now)
				write_n_save_status("rra", stack);
		}
		else
		{
			i = -1;
			while (++i < stack->a[idx->a].now)
				write_n_save_status("ra", stack);
		}
	}
	else
		check_n_display_oper_2(stack, dest_order, idx);
}
