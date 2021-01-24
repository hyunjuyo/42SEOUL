/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 13:02:45 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/01/18 18:07:18 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_flags_u(unsigned int n, const char *args, t_flags *flags)
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
	start_printf_u(n, flags);
}

void	check_flags_x(unsigned int n, const char *args, t_flags *flags)
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
	if (args[flags->i] == 'X')
		start_printf_x(n, flags, 'X');
	else
		start_printf_x(n, flags, 'x');
}
