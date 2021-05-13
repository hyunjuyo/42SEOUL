/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_n_exec_inst.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 16:54:49 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/05/13 16:57:42 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_exec(char *oper, t_stack *stack)
{
	if (ft_strncmp(oper, "sa", OPER_LEN + 1) == 0)
		operations_sa(stack);
	else if (ft_strncmp(oper, "sb", OPER_LEN + 1) == 0)
		operations_sb(stack);
	else if (ft_strncmp(oper, "ss", OPER_LEN + 1) == 0)
		operations_ss(stack);
	else if (ft_strncmp(oper, "pa", OPER_LEN + 1) == 0)
		operations_pa(stack);
	else if (ft_strncmp(oper, "pb", OPER_LEN + 1) == 0)
		operations_pb(stack);
	else if (ft_strncmp(oper, "ra", OPER_LEN + 1) == 0)
		operations_ra(stack);
	else if (ft_strncmp(oper, "rb", OPER_LEN + 1) == 0)
		operations_rb(stack);
	else if (ft_strncmp(oper, "rr", OPER_LEN + 1) == 0)
		operations_rr(stack);
	else if (ft_strncmp(oper, "rra", OPER_LEN + 1) == 0)
		operations_rra(stack);
	else if (ft_strncmp(oper, "rrb", OPER_LEN + 1) == 0)
		operations_rrb(stack);
	else
		operations_rrr(stack);
}

void	exec_inst(t_stack *stack)
{
	int		i;

	i = -1;
	while (++i < stack->inst_count)
		do_exec(stack->inst[i], stack);
}

void	check_n_clear_color_setting(char **line)
{
	if (ft_strncmp(*line, "\033[1;32msa", ft_strlen(*line)) == 0)
	{
		free(*line);
		*line = ft_strdup("sa");
	}
	else if (ft_strncmp(*line, "\033[1;32mpa", ft_strlen(*line)) == 0)
	{
		free(*line);
		*line = ft_strdup("pa");
	}
}

void	read_inst(t_stack *stack)
{
	char	*line;
	int		i;

	i = 0;
	while (get_next_line(0, &line) == 1)
	{
		check_n_clear_color_setting(&line);
		if (ft_strlen(line) > OPER_LEN)
			print_error("Error", 1);
		ft_strlcpy(stack->inst[i], line, OPER_LEN + 1);
		error_check_inst(stack, i);
		free(line);
		line = NULL;
		i++;
	}
	if (i == 0)
	{
		check_stack_sorted(stack);
		exit(0);
	}
	if (ft_strlen(line) != 0)
		print_error("Error", 1);
	free(line);
	line = NULL;
	stack->inst_count = i;
}
