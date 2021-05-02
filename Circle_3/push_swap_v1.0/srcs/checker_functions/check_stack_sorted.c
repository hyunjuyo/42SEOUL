/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack_sorted.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 15:23:37 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/04/25 15:32:43 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_stack_sorted(t_stack *stack)
{
	int	i;
	int	check;

	check = 0;
	i = 0;
	while (i < stack->a_count - 1)
	{
		if (stack->a[i].num >= stack->a[i + 1].num)
			break ;
		i++;
	}
	if (i == stack->a_count - 1)
		check = 1;
	if (check == 1 && stack->b[0].num == EMPTY)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
