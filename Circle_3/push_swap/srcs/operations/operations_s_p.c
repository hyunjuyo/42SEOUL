/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_s_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 19:56:37 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/04/27 18:07:19 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	operations_sa(t_stack *stack)
{
	t_num_info	temp;

	if (stack->a[0].num == EMPTY || stack->a[1].num == EMPTY)
        return ;
	ft_memcpy(&temp, &stack->a[0], sizeof(t_num_info));
	ft_memcpy(&stack->a[0], &stack->a[1], sizeof(t_num_info));
	stack->a[0].now--;
	ft_memcpy(&stack->a[1], &temp, sizeof(t_num_info));
	stack->a[1].now++;
}

void	operations_sb(t_stack *stack)
{
	t_num_info	temp;

	if (stack->b[0].num == EMPTY || stack->b[1].num == EMPTY)
        return ;
	ft_memcpy(&temp, &stack->b[0], sizeof(t_num_info));
	ft_memcpy(&stack->b[0], &stack->b[1], sizeof(t_num_info));
	stack->b[0].now++;
	ft_memcpy(&stack->b[1], &temp, sizeof(t_num_info));
	stack->b[1].now--;
}

void	operations_ss(t_stack *stack)
{
	operations_sa(stack);
	operations_sb(stack);
}

void	operations_pa(t_stack *stack)
{
	int	i;

	if (stack->b[0].num == EMPTY)
        return ;
	i = 0;
	while (i < stack->a_count)
	{
		ft_memcpy(&stack->a[stack->a_count - i],
				&stack->a[stack->a_count - i - 1], sizeof(t_num_info));
		i++;
	}
	ft_memcpy(&stack->a[0], &stack->b[0], sizeof(t_num_info));
	stack->a_count++;
	stack->b_count--;
	i = 0;
	while (i < stack->b_count)
	{
		ft_memcpy(&stack->b[i], &stack->b[i + 1], sizeof(t_num_info));
		i++;
	}
	ft_memset(&stack->b[i], 0, sizeof(t_num_info));
	stack->b[i].num = EMPTY;
}

void	operations_pb(t_stack *stack)
{
	int	i;

	if (stack->a[0].num == EMPTY)
        return ;
	i = 0;
	while (i < stack->b_count)
	{
		ft_memcpy(&stack->b[stack->b_count - i],
				&stack->b[stack->b_count - i - 1], sizeof(t_num_info));
		i++;
	}
	ft_memcpy(&stack->b[0], &stack->a[0], sizeof(t_num_info));
	stack->b_count++;
	stack->a_count--;
	i = 0;
	while (i < stack->a_count)
	{
		ft_memcpy(&stack->a[i], &stack->a[i + 1], sizeof(t_num_info));
		i++;
	}
	ft_memset(&stack->a[i], 0, sizeof(t_num_info));
	stack->a[i].num = EMPTY;
}
