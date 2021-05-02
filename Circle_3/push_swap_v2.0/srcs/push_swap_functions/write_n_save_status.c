/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_n_save_status.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 17:57:08 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/05/01 16:07:37 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	write_n_save_status_last(char *oper, t_stack *stack)
{
	if (ft_strncmp(oper, "rr", OPER_LEN + 1) == 0)
	{
		write(1, "rr\n", 3);
		operations_rr(stack);
		if (stack->debug_opt == 1 || stack->debug_opt2 == 1)
			print_stack_status(stack);
	}
}

void	write_n_save_status3(char *oper, t_stack *stack)
{
	if (ft_strncmp(oper, "sa", OPER_LEN + 1) == 0)
	{
		write(1, "sa\n", 3);
		operations_sa(stack);
		if (stack->debug_opt == 1 || stack->debug_opt2 == 1)
			print_stack_status(stack);
	}
	else if (ft_strncmp(oper, "sb", OPER_LEN + 1) == 0)
	{
		write(1, "sb\n", 3);
		operations_sb(stack);
		if (stack->debug_opt == 1 || stack->debug_opt2 == 1)
			print_stack_status(stack);
	}
	else if (ft_strncmp(oper, "ss", OPER_LEN + 1) == 0)
	{
		write(1, "ss\n", 3);
		operations_ss(stack);
		if (stack->debug_opt == 1 || stack->debug_opt2 == 1)
			print_stack_status(stack);
	}
	else
		write_n_save_status_last(oper, stack);
}

void	write_n_save_status2(char *oper, t_stack *stack)
{
	if (ft_strncmp(oper, "pa", OPER_LEN + 1) == 0)
	{
		write(1, "pa\n", 3);
		operations_pa(stack);
		if (stack->debug_opt == 1 || stack->debug_opt2 == 1)
			print_stack_status(stack);
	}
	else if (ft_strncmp(oper, "rb", OPER_LEN + 1) == 0)
	{
		write(1, "rb\n", 3);
		operations_rb(stack);
		if (stack->debug_opt == 1 || stack->debug_opt2 == 1)
			print_stack_status(stack);
	}
	else if (ft_strncmp(oper, "rrb", OPER_LEN + 1) == 0)
	{
		write(1, "rrb\n", 4);
		operations_rrb(stack);
		if (stack->debug_opt == 1 || stack->debug_opt2 == 1)
			print_stack_status(stack);
	}
	else
		write_n_save_status3(oper, stack);
}

void	write_n_save_status(char *oper, t_stack *stack)
{
	if (ft_strncmp(oper, "ra", OPER_LEN + 1) == 0)
	{
		write(1, "ra\n", 3);
		operations_ra(stack);
		if (stack->debug_opt == 1 || stack->debug_opt2 == 1)
			print_stack_status(stack);
	}
	else if (ft_strncmp(oper, "rra", OPER_LEN + 1) == 0)
	{
		write(1, "rra\n", 4);
		operations_rra(stack);
		if (stack->debug_opt == 1 || stack->debug_opt2 == 1)
			print_stack_status(stack);
	}
	else if (ft_strncmp(oper, "pb", OPER_LEN + 1) == 0)
	{
		write(1, "pb\n", 3);
		operations_pb(stack);
		if (stack->debug_opt == 1 || stack->debug_opt2 == 1)
			print_stack_status(stack);
	}
	else
		write_n_save_status2(oper, stack);
}
