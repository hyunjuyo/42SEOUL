/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_n_display_oper_utils2.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 17:09:52 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/05/14 12:03:09 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		last_reverse_rotate_check(t_stack *stack)
{
	int	total;
	int	i;
	int	idx;
	int	dest_order;
	int	check_order;

	if (stack->b_count != 0)
		return (0);
	total = stack->a_count + stack->b_count;
	i = 0;
	while (i < total)
	{
		dest_order = total - i;
		idx = get_dest_order_idx_a(stack, dest_order);
		if ((check_order = dest_order - 1) == 0)
			check_order = total;
		if (stack->a[idx].now != check_order)
			break ;
		i++;
	}
	if (i == total)
		return (1);
	else
		return (0);
}

int		last_rotate_check(t_stack *stack)
{
	int	total;
	int	i;
	int	idx;
	int	dest_order;
	int	check_order;

	if (stack->b_count != 0)
		return (0);
	total = stack->a_count + stack->b_count;
	i = 0;
	while (i < total)
	{
		dest_order = total - i;
		idx = get_dest_order_idx_a(stack, dest_order);
		if ((check_order = dest_order + 1) == total + 1)
			check_order = 1;
		if (stack->a[idx].now != check_order)
			break ;
		i++;
	}
	if (i == total)
		return (1);
	else
		return (0);
}

void	display_after_color_setting_ra(t_stack *stack, t_idx *idx)
{
	int	i;

	if (stack->a[idx->a].now - stack->b_count > stack->a_count / 2)
	{
		i = -1;
		while (++i < stack->a_count -
				(stack->a[idx->a].now - stack->b_count))
		{
			if (last_reverse_rotate_check(stack) == 1 &&
					(stack->color_opt == 1 || stack->color_opt2 == 1))
				stack->set_color = 1;
			write_n_save_status("rra", stack);
		}
	}
	else
	{
		i = -1;
		while (++i < stack->a[idx->a].now - stack->b_count)
		{
			if (last_rotate_check(stack) == 1 && (stack->color_opt == 1 ||
						stack->color_opt2 == 1))
				stack->set_color = 1;
			write_n_save_status("ra", stack);
		}
	}
}

void	display_after_color_setting_sa(t_stack *stack, int now_order)
{
	if (now_order == 1)
	{
		if (stack->color_opt == 1 || stack->color_opt2 == 1)
			stack->set_color = 1;
		write_n_save_status("sa", stack);
	}
}
