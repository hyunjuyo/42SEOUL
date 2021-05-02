/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_oper_for_sort_utils.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 16:50:51 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/05/02 16:39:34 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sub_grouping_numbers_step2(t_stack *stack, int scale, int i)
{
	int	count_pa;
	int	count_rb;
	int	j;

	count_pa = 0;
	count_rb = 0;
	j = -1;
	while (++j < scale * 2 / 3)
	{
		if (stack->b[0].dest > scale * 2 / 3 + scale * (i - 1))
		{
			write_n_save_status("pa", stack);
			count_pa++;
		}
		else
		{
			write_n_save_status("rb", stack);
			count_rb++;
		}
		if (count_pa == scale / 3 || count_rb == scale / 3)
			break ;
	}
	j = -1;
	while (++j < count_pa)
		write_n_save_status("pb", stack);
}

void	sub_grouping_numbers_step1(t_stack *stack, int scale, int i)
{
	if (stack->b[1].num != EMPTY && stack->b[0].dest <
			scale / 3 + scale * (i - 1))
	{
		if (stack->a[0].dest > scale * i)
			write_n_save_status("rr", stack);
		else
			write_n_save_status("rb", stack);
	}
}
