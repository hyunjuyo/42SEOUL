/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 16:12:51 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/05/14 17:02:24 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack *stack)
{
	int	i;

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
	int	i;

	i = 0 + stack->debug_opt + stack->color_opt;
	while (i < idx)
	{
		if (stack->a[i].num == num)
			print_error("Error", 1);
		i++;
	}
}

void	check_options(int argc, char *argv[], t_stack *stack)
{
	if (ft_strncmp(argv[1], "-v", 3) == 0 ||
			(ft_strncmp(argv[1], "-c", 3) == 0 &&
			 ft_strncmp(argv[2], "-v", 3) == 0))
		stack->debug_opt = 1;
	else if (ft_strncmp(argv[argc - 1], "-v", 3) == 0 ||
			(ft_strncmp(argv[argc - 2], "-v", 3) == 0 &&
			 ft_strncmp(argv[argc - 1], "-c", 3) == 0))
		stack->debug_opt2 = 1;
	if (ft_strncmp(argv[1], "-c", 3) == 0 ||
			(ft_strncmp(argv[1], "-v", 3) == 0 &&
			 ft_strncmp(argv[2], "-c", 3) == 0))
		stack->color_opt = 1;
	else if (ft_strncmp(argv[argc - 1], "-c", 3) == 0 ||
			(ft_strncmp(argv[argc - 2], "-c", 3) == 0 &&
			 ft_strncmp(argv[argc - 1], "-v", 3) == 0))
		stack->color_opt2 = 1;
}

int		main(int argc, char *argv[])
{
	t_stack	stack;
	int		i;
	int		num;

	if (argc == 1 || (argc == 2 && ft_strncmp(argv[1], "-v", 3) == 0) ||
			(argc == 2 && ft_strncmp(argv[1], "-c", 3) == 0))
		exit(0);
	ft_memset(&stack, 0, sizeof(t_stack));
	check_options(argc, argv, &stack);
	init_stack(&stack);
	i = 0 + stack.debug_opt + stack.color_opt;
	while (i < argc - 1 - stack.debug_opt2 - stack.color_opt2)
	{
		num = atoi_error_check(argv[i + 1]);
		check_error_dup(&stack, i, num);
		stack.a[i - stack.debug_opt - stack.color_opt].num = num;
		i++;
	}
	stack.a_count = i - stack.debug_opt - stack.color_opt;
	save_now_n_dest_order(&stack);
	find_min_oper_for_sort(&stack);
	return (0);
}
