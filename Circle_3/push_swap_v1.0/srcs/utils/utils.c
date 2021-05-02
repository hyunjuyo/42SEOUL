/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 17:43:15 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/04/25 19:17:06 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack_status(t_stack *stack)
{
	int		i;
	char	*num;

	write(1, "[b] ", 4);
	i = -1;
	while (++i < stack->b_count)
	{
		num = ft_itoa(stack->b[i].num);
		write(1, num, ft_strlen(num));
		write(1, " ", 1);
	}
	write(1, "\n", 1);
	write(1, "[a] ", 4);
	i = -1;
	while (++i < stack->a_count)
	{
		num = ft_itoa(stack->a[i].num);
		write(1, num, ft_strlen(num));
		write(1, " ", 1);
	}
	write(1, "\n", 1);
}

void	print_error(char *message, int type)
{
	write(1, message, ft_strlen(message));
	write(1, "\n", 1);
	write(3, message, ft_strlen(message));
	write(3, "\n", 1);
    if (type == 1)
		exit(1);
}

void	error_check_inst(t_stack *stack, int i)
{
	if (ft_strncmp(stack->inst[i], "sa", OPER_LEN + 1) == 0)
		return ;
	else if (ft_strncmp(stack->inst[i], "sb", OPER_LEN + 1) == 0)
		return ;
	else if (ft_strncmp(stack->inst[i], "ss", OPER_LEN + 1) == 0)
		return ;
	else if (ft_strncmp(stack->inst[i], "pa", OPER_LEN + 1) == 0)
		return ;
	else if (ft_strncmp(stack->inst[i], "pb", OPER_LEN + 1) == 0)
		return ;
	else if (ft_strncmp(stack->inst[i], "ra", OPER_LEN + 1) == 0)
		return ;
	else if (ft_strncmp(stack->inst[i], "rb", OPER_LEN + 1) == 0)
		return ;
	else if (ft_strncmp(stack->inst[i], "rr", OPER_LEN + 1) == 0)
		return ;
	else if (ft_strncmp(stack->inst[i], "rra", OPER_LEN + 1) == 0)
		return ;
	else if (ft_strncmp(stack->inst[i], "rrb", OPER_LEN + 1) == 0)
		return ;
	else if (ft_strncmp(stack->inst[i], "rrr", OPER_LEN + 1) == 0)
		return ;
	else
		print_error("Error", 1);
}
