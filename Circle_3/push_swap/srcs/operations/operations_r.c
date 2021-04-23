/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_r.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 19:59:25 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/04/23 15:03:05 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	operations_ra(t_stack *stack)
{
	int			i;
	long long	temp;

	temp = stack->a[0];
	i = 0;
	while (i < stack->a_count - 1)
	{
		stack->a[i] = stack->a[i + 1];
		i++;
	}
	stack->a[i] = temp;
}

void	operations_rb(t_stack *stack)
{
	int			i;
	long long	temp;

	temp = stack->b[0];
	i = 0;
	while (i < stack->b_count - 1)
	{
		stack->b[i] = stack->b[i + 1];
		i++;
	}
	stack->b[i] = temp;
}

void	operations_rr(t_stack *stack)
{
	operations_ra(stack);
	operations_rb(stack);
}
