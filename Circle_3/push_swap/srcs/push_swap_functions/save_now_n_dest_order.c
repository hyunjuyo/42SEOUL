/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_now_n_dest_order.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 15:51:46 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/04/25 17:38:32 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	save_now_n_dest_order(t_stack *stack)
{
	int	i;
	int	j;
	int	now_order;
	int	dest_order;

	i = 0;
	while (i < stack->a_count)
	{
		now_order = i + 1;
		stack->a[i].now = now_order;
		dest_order = 1;
		j = 0;
		while (j < stack->a_count)
		{
			if (stack->a[j].num < stack->a[i].num)
				dest_order++;
			j++;
		}
		stack->a[i].dest = dest_order;
		i++;
	}
}
