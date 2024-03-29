/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 16:12:51 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/04/27 19:03:17 by hyunjuyo         ###   ########.fr       */
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

    i = 0;
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
//	i = -1;  //test
//	while (++i < argc - 1)  //test
//		printf("%lld ", stack.a[i].num);  //test
    read_inst(&stack);
    exec_inst(&stack);
//    printf("--------------------\n"); //test
//	i = -1; //test
//	while (++i < stack.a_count) //test
//		printf("[a] %lld,\t[b] %lld\n",stack.a[i].num, stack.b[i].num); //test
    check_stack_sorted(&stack);
	return (0);
}
