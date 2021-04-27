/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 16:12:51 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/04/27 14:15:46 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>  //test

void    init_stack(t_stack *stack)
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

void    check_error_dup(t_stack *stack, int idx, int num)
{
    int i;

    i = 0 + stack->debug_opt;
    while (i < idx)
    {
        if (stack->a[i].num == num) //duplicate
            print_error("Error", 1);
        i++;
    }
}

int		main(int argc, char *argv[])
{
    t_stack stack;
	int     i;
    int     num;

	if (argc == 1 || (argc == 2 && ft_strncmp(argv[1], "-v", 3) == 0))
		exit(0);
	ft_memset(&stack, 0, sizeof(t_stack));
    if (ft_strncmp(argv[1], "-v", 3) == 0)
        stack.debug_opt = 1;
    init_stack(&stack);
	i = 0 + stack.debug_opt;
	while (i < argc - 1)
	{
        num = atoi_error_check(argv[i + 1]);
        check_error_dup(&stack, i, num);
		stack.a[i - stack.debug_opt].num = num;
		i++;
	}
    stack.a_count = i - stack.debug_opt;
	save_now_n_dest_order(&stack);
	find_min_oper_for_sort(&stack);
    printf("\n--------------------\n"); //test
	i = -1; //test
	while (++i < stack.a_count) //test
		printf("[a] %lld,\tnow : %d, dest : %d\n",stack.a[i].num, stack.a[i].now, stack.a[i].dest); //test
	return (0);
}
