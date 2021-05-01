/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_oper_for_sort_utils.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 16:50:51 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/05/01 16:35:25 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
