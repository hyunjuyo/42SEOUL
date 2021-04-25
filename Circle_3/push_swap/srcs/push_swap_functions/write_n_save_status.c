/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_n_save_status.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 17:57:08 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/04/25 20:25:51 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	write_n_save_status(char *oper, t_stack *stack)
{
	if (ft_strncmp(oper, "ra", OPER_LEN + 1) == 0)
	{
		write(1, "ra\n", 3);
		operations_ra(stack);
		if (stack->debug_opt == 1)
			print_stack_status(stack);
	}
	else if (ft_strncmp(oper, "rra", OPER_LEN + 1) == 0)
	{
		write(1, "rra\n", 4);
		operations_rra(stack);
		if (stack->debug_opt == 1)
			print_stack_status(stack);
	}
	else if (ft_strncmp(oper, "pb", OPER_LEN + 1) == 0)
	{
		write(1, "pb\n", 3);
		operations_pb(stack);
		if (stack->debug_opt == 1)
			print_stack_status(stack);
	}
	else if (ft_strncmp(oper, "pa", OPER_LEN + 1) == 0)
	{
		write(1, "pa\n", 3);
		operations_pb(stack);
		if (stack->debug_opt == 1)
			print_stack_status(stack);
	}
	else if (ft_strncmp(oper, "rb", OPER_LEN + 1) == 0)
	{
		write(1, "rb\n", 3);
		operations_pb(stack);
		if (stack->debug_opt == 1)
			print_stack_status(stack);
	}
	else if (ft_strncmp(oper, "rrb", OPER_LEN + 1) == 0)
	{
		write(1, "rrb\n", 4);
		operations_pb(stack);
		if (stack->debug_opt == 1)
			print_stack_status(stack);
	}
	else if (ft_strncmp(oper, "sa", OPER_LEN + 1) == 0)
	{
		write(1, "sa\n", 3);
		operations_pb(stack);
		if (stack->debug_opt == 1)
			print_stack_status(stack);
	}



}
