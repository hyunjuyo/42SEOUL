/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 19:59:55 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/04/27 13:10:42 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	operations_rra(t_stack *stack)
{
	int			i;
	t_num_info	temp;
	int			move_count;

	move_count = stack->a_count - 1;
	ft_memcpy(&temp, &stack->a[move_count], sizeof(t_num_info));
	i = 0;
	while (i < move_count)
	{
		ft_memcpy(&stack->a[move_count - i], &stack->a[move_count - i - 1],
				sizeof(t_num_info));
		stack->a[move_count - i].now++;
		i++;
	}
	ft_memcpy(&stack->a[0], &temp, sizeof(t_num_info));
	stack->a[0].now = stack->b_count + 1;
}

void	operations_rrb(t_stack *stack)
{
	int			i;
	t_num_info	temp;
	int			move_count;

	move_count = stack->b_count - 1;
	ft_memcpy(&temp, &stack->b[move_count], sizeof(t_num_info));
	i = 0;
	while (i < move_count)
	{
		ft_memcpy(&stack->b[move_count - i], &stack->b[move_count - i - 1],
				sizeof(t_num_info));
		stack->b[move_count - i].now--;
		i++;
	}
	ft_memcpy(&stack->b[0], &temp, sizeof(t_num_info));
	stack->b[0].now = stack->b_count;
}

void	operations_rrr(t_stack *stack)
{
	operations_rra(stack);
	operations_rrb(stack);
}
