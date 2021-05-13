/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_r.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 19:59:25 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/04/29 14:43:17 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	operations_ra(t_stack *stack)
{
	int			i;
	t_num_info	temp;

	ft_memcpy(&temp, &stack->a[0], sizeof(t_num_info));
	i = 0;
	while (i < stack->a_count - 1)
	{
		ft_memcpy(&stack->a[i], &stack->a[i + 1], sizeof(t_num_info));
		stack->a[i].now--;
		i++;
	}
	ft_memcpy(&stack->a[i], &temp, sizeof(t_num_info));
	stack->a[i].now = stack->a_count + stack->b_count;
}

void	operations_rb(t_stack *stack)
{
	int			i;
	t_num_info	temp;

	ft_memcpy(&temp, &stack->b[0], sizeof(t_num_info));
	i = 0;
	while (i < stack->b_count - 1)
	{
		ft_memcpy(&stack->b[i], &stack->b[i + 1], sizeof(t_num_info));
		stack->b[i].now++;
		i++;
	}
	ft_memcpy(&stack->b[i], &temp, sizeof(t_num_info));
	stack->b[i].now = 1;
}

void	operations_rr(t_stack *stack)
{
	operations_ra(stack);
	operations_rb(stack);
}
