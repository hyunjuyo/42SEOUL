/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 13:02:45 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/01/19 17:42:12 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_flags_c(char n, const char *args, t_flags *flags)
{
	int		start;

	start = flags->i;
	while (args[--start] != '%')
		;
	while (args[++start] == '-')
		flags->isminus = 1;
	while (args[start] == '0')
	{
		flags->iszero = 1;
		start++;
	}
	check_w_p(args, &start, flags);
	start_printf_c(n, flags);
}

void	check_flags_s(char *str, const char *args, t_flags *flags)
{
	int		start;

	start = flags->i;
	while (args[start] != '%')
		start--;
	while (args[++start] == '-')
		flags->isminus = 1;
	while (args[start] == '0')
	{
		flags->iserror = 1;
		return ;
	}
	check_w_p(args, &start, flags);
	start_printf_s(str, flags);
}

void	check_flags_p(void *ptr, const char *args, t_flags *flags)
{
	int		start;

	start = flags->i;
	while (args[start] != '%')
		start--;
	while (args[++start] == '-')
		flags->isminus = 1;
	while (args[start] == '0')
	{
		flags->iserror = 1;
		return ;
	}
	check_w_p(args, &start, flags);
	start_printf_p(ptr, flags);
}

void	check_flags_di(int n, const char *args, t_flags *flags)
{
	int		start;

	start = flags->i;
	while (args[start] != '%')
		start--;
	while (args[++start] == '-' || args[start] == '0')
	{
		if (args[start] == '-')
			flags->isminus = 1;
		if (args[start] == '0')
			flags->iszero = 1;
	}
	check_w_p(args, &start, flags);
	start_printf_di(n, flags);
}
