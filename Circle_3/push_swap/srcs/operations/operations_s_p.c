/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_s_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 19:56:37 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/04/23 15:02:50 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	operations_sa(t_stack *stack)
{
	long long	temp;

	if (stack->a[0] == NOT_INT || stack->a[1] == NOT_INT)
        return ;
	temp = stack->a[0];
	stack->a[0] = stack->a[1];
	stack->a[1] = temp;
}

void	operations_sb(t_stack *stack)
{
	long long	temp;

	if (stack->b[0] == NOT_INT || stack->b[1] == NOT_INT)
        return ;
	temp = stack->b[0];
	stack->b[0] = stack->b[1];
	stack->b[1] = temp;
}

void	operations_ss(t_stack *stack)
{
	operations_sa(stack);
	operations_sb(stack);
}

void	operations_pa(t_stack *stack)
{
	int	i;

	if (stack->b[0] == NOT_INT)
        return ;
	i = 0;
	while (i < stack->a_count)
	{
		stack->a[stack->a_count - i] = stack->a[stack->a_count - i - 1];
		i++;
	}
	stack->a[0] = stack->b[0];
	stack->a_count++;
	stack->b_count--;
	i = 0;
	while (i < stack->b_count)
	{
		stack->b[i] = stack->b[i + 1];
		i++;
	}
	stack->b[i] = NOT_INT;
}

void	operations_pb(t_stack *stack)
{
	int	i;

	if (stack->a[0] == NOT_INT)
        return ;
	i = 0;
	while (i < stack->b_count)
	{
		stack->b[stack->b_count - i] = stack->b[stack->b_count - i - 1];
		i++;
	}
	stack->b[0] = stack->a[0];
	stack->b_count++;
	stack->a_count--;
	i = 0;
	while (i < stack->a_count)
	{
		stack->a[i] = stack->a[i + 1];
		i++;
	}
	stack->a[i] = NOT_INT;
}
