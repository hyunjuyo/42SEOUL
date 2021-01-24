/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags_wp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 18:51:52 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/01/19 17:42:56 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		do_atoi(const char *args, int *i)
{
	int	num;

	num = 0;
	while (args[*i] >= '0' && args[*i] <= '9')
	{
		num *= 10;
		num += args[*i] - '0';
		(*i)++;
	}
	return (num);
}

void	atoi_dot_zero(const char *args, int *i, t_flags *flags)
{
	int	num;

	num = do_atoi(args, i);
	if (*i == flags->i)
		flags->width = num;
	else if (args[*i] == '*' && *i + 1 == flags->i)
		flags->width = flags->isast1;
	else
		flags->iserror = 1;
}

void	atoi_dot_one(const char *args, int *i, t_flags *flags)
{
	int	num;

	num = do_atoi(args, i);
	if (args[*i] == '.')
		flags->width = num;
	else if (args[*i] == '*' && args[*i + 1] == '.')
	{
		flags->width = flags->isast1;
		(*i)++;
	}
	else
		flags->iserror = 1;
	(*i)++;
	num = do_atoi(args, i);
	if (*i == flags->i)
		flags->prcs = num;
	else if (args[*i] == '*' && *i + 1 == flags->i)
		flags->prcs = flags->isast2;
	else
		flags->iserror = 1;
}

void	check_w_p(const char *args, int *start, t_flags *flags)
{
	int	i;
	int	count_dot;
	int	count_ast;

	count_dot = 0;
	count_ast = 0;
	i = *start;
	while (i < flags->i)
	{
		if (args[i] == '.')
			count_dot++;
		if (args[i] == '*')
			count_ast++;
		i++;
	}
	if (count_dot > 1 || count_ast > 2)
	{
		flags->iserror = 1;
		return ;
	}
	if (count_dot == 0)
		atoi_dot_zero(args, start, flags);
	if (count_dot == 1)
		atoi_dot_one(args, start, flags);
}
