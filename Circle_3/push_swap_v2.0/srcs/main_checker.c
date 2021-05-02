/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 16:12:51 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/05/01 16:49:33 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack *stack)
{
	int i;

	i = 0;
	while (i < STACK_SIZE)
	{
		stack->a[i].num = EMPTY;
		stack->b[i].num = EMPTY;
		i++;
	}
}

void	check_error_dup(t_stack *stack, int idx, int num)
{
	int i;

	i = 0;
	while (i < idx)
	{
		if (stack->a[i].num == num)
			print_error("Error", 1);
		i++;
	}
}

int		main(int argc, char *argv[])
{
	t_stack	stack;
	int		i;
	int		num;

	if (argc == 1)
		exit(0);
	ft_memset(&stack, 0, sizeof(t_stack));
	init_stack(&stack);
	i = 0;
	while (i < argc - 1)
	{
		num = atoi_error_check(argv[i + 1]);
		check_error_dup(&stack, i, num);
		stack.a[i].num = num;
		i++;
	}
	stack.a_count = i;
	read_inst(&stack);
	exec_inst(&stack);
	check_stack_sorted(&stack);
	return (0);
}
