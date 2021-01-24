/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 18:42:32 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/01/18 19:41:27 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_ast(va_list ap, const char *args, t_flags *flags)
{
	char	*arr;
	int		chk_dot;

	chk_dot = 0;
	arr = "-0.*123456789";
	while (ft_strchr(arr, args[++(flags->i)]) != 0)
	{
		if (args[flags->i] == '.')
			chk_dot = 1;
		if (args[flags->i] == '*' && chk_dot == 0)
			flags->isast1 = va_arg(ap, int);
		else if (args[flags->i] == '*' && chk_dot == 1)
			flags->isast2 = va_arg(ap, int);
	}
}

int		check_start(va_list ap, const char *args, t_flags *flags)
{
	check_ast(ap, args, flags);
	if (args[flags->i] == 'c')
		check_flags_c((char)va_arg(ap, int), args, flags);
	else if (args[flags->i] == 's')
		check_flags_s(va_arg(ap, char *), args, flags);
	else if (args[flags->i] == 'p')
		check_flags_p(va_arg(ap, void *), args, flags);
	else if (args[flags->i] == 'd' || args[flags->i] == 'i')
		check_flags_di(va_arg(ap, int), args, flags);
	else if (args[flags->i] == 'u')
		check_flags_u(va_arg(ap, unsigned int), args, flags);
	else if (args[flags->i] == 'x' || args[flags->i] == 'X')
		check_flags_x(va_arg(ap, unsigned int), args, flags);
	else if (args[flags->i] == '%')
		check_flags_c('%', args, flags);
	else
		return (0);
	return (1);
}

int		ft_printf(const char *args, ...)
{
	va_list		ap;
	t_flags		flags;
	int			temp[2];

	va_start(ap, args);
	ft_memset(&flags, -1, sizeof(flags));
	flags.count = 0;
	while (args[++(flags.i)])
	{
		if (args[flags.i] == '%')
		{
			if (check_start(ap, args, &flags) == 0 || flags.iserror == 1)
				return (0);
			temp[0] = flags.i;
			temp[1] = flags.count;
			ft_memset(&flags, -1, sizeof(flags));
			flags.i = temp[0];
			flags.count = temp[1];
			continue;
		}
		write(1, &args[flags.i], 1);
		flags.count++;
	}
	va_end(ap);
	return (flags.count);
}
