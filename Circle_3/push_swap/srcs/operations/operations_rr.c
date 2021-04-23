/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 19:59:55 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/04/23 15:03:16 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	operations_rra(t_stack *stack)
{
	int			i;
	long long	temp;
	int			move_count;

	move_count = stack->a_count - 1;
	temp = stack->a[move_count];
	i = 0;
	while (i < move_count)
	{
		stack->a[move_count - i] = stack->a[move_count - i - 1];
		i++;
	}
	stack->a[0] = temp;
}

void	operations_rrb(t_stack *stack)
{
	int			i;
	long long	temp;
	int			move_count;

	move_count = stack->b_count - 1;
	temp = stack->b[move_count];
	i = 0;
	while (i < move_count)
	{
		stack->b[move_count - i] = stack->b[move_count - i - 1];
		i++;
	}
	stack->b[0] = temp;
}

void	operations_rrr(t_stack *stack)
{
	operations_rra(stack);
	operations_rrb(stack);
}
