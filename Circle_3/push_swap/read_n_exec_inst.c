/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_n_exec_inst.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 16:54:49 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/04/22 20:02:26 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_exec(char *oper, t_stack *stack)
{
	if (ft_strncmp(oper, "sa", OPER_LEN + 1) == 0)
		operations_sa(stack);

}

void	exec_inst(t_stack *stack)
{
	int		i;

	i = -1;
	while (++i < stack->inst_num)
		do_exec(stack->inst[i], stack);
}

void	read_inst(t_stack *stack)
{
	char	*line;
	int		i;

	i = 0;
	while (get_next_line(0, &line) == 1)
	{
		if (ft_strlen(line) > OPER_LEN) //incorrectly formatted
			print_error("Error", 1);
		ft_strlcpy(stack->inst[i], line, OPER_LEN + 1);
		error_check_inst(stack, i); //incorrectly formatted
		free(line);
		line = NULL;
		i++;
	}
	if (i == 0 || ft_strlen(line) != 0)  //instruction don't exist or incorrectly formatted
    	print_error("Error", 1);
	free(line);
	line = NULL;
	stack->inst_num = i;
	i = -1;  //test
	while (++i < stack->inst_num)  //test
		printf("%s ", stack->inst[i]);  //test
	printf("\n"); //test
	i = -1; //test
	while (++i < 5) //test
		printf("[a] %lld,\t[b] %lld\n",stack->a[i], stack->b[i]); //test
}
