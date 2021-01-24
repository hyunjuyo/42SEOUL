/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_printf_di.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 22:10:54 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/01/19 17:48:35 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	do_printf_di_basic(char *ptr_n, char *ptr_t, t_opts *opt)
{
	int	i;

	i = -1;
	while (++i < opt->len_max - (opt->len_n + opt->minus))
		ptr_t[i] = ' ';
	ptr_t[i] = (opt->minus == 1) ? '-' : 0;
	i += opt->minus;
	i--;
	while (++i < opt->len_max)
		ptr_t[i] = ptr_n[i - (opt->len_max - (opt->len_n + opt->minus))];
}

void	do_printf_di_py(char *ptr_n, char *ptr_t, t_opts *opt, t_flags *flags)
{
	int	i;

	if (ptr_n[0] == '0' && ptr_n[1] == '\0' && flags->prcs == 0)
		opt->len_prcs = 0;
	if (flags->isminus == 1)
	{
		ptr_t[0] = (opt->minus == 1) ? '-' : 0;
		i = -1 + opt->minus;
		while (++i < opt->len_prcs + opt->minus)
			ptr_t[i] = ptr_n[i];
		while (i < opt->len_max)
			ptr_t[i++] = ' ';
	}
	else
	{
		i = -1;
		while (++i < opt->len_max - (opt->len_prcs + opt->minus))
			ptr_t[i] = ' ';
		ptr_t[i] = (opt->minus == 1) ? '-' : 0;
		i += opt->minus;
		i--;
		while (++i < opt->len_max)
			ptr_t[i] = ptr_n[i - (opt->len_max - (opt->len_prcs + opt->minus))];
	}
}

void	do_printf_di_pn(char *ptr_n, char *ptr_t, t_opts *opt, t_flags *flags)
{
	int	i;

	if (flags->isminus == 1)
	{
		ptr_t[0] = (opt->minus == 1) ? '-' : 0;
		i = -1 + opt->minus;
		while (++i < opt->len_n + opt->minus)
			ptr_t[i] = ptr_n[i];
		while (i < opt->len_max)
			ptr_t[i++] = ' ';
	}
	else if (flags->iszero == 1)
	{
		ptr_t[0] = (opt->minus == 1) ? '-' : 0;
		i = -1 + opt->minus;
		while (++i < opt->len_max - opt->len_n)
			ptr_t[i] = '0';
		i--;
		while (++i < opt->len_max)
			ptr_t[i] = ptr_n[i - (opt->len_max - opt->len_n) + opt->minus];
	}
	else
		do_printf_di_basic(ptr_n, ptr_t, opt);
}

void	do_printf_di(char *ptr_n, t_opts *opt, t_flags *flags)
{
	char	*ptr_t;
	char	*temp;
	int		i;

	ptr_t = malloc(sizeof(char) * opt->len_max);
	opt->len_n = ft_strlen(ptr_n) - opt->minus;
	opt->len_prcs = (flags->prcs > opt->len_n) ? flags->prcs : opt->len_n;
	temp = malloc(sizeof(char) * (opt->len_prcs + opt->minus));
	temp[0] = (opt->minus == 1) ? '-' : 0;
	i = -1 + opt->minus;
	while (++i < opt->len_prcs - opt->len_n + opt->minus)
		temp[i] = '0';
	i--;
	while (++i < opt->len_prcs + opt->minus)
		temp[i] = ptr_n[i - (opt->len_prcs - opt->len_n)];
	free(ptr_n);
	ptr_n = temp;
	if (flags->prcs >= 0)
		do_printf_di_py(ptr_n, ptr_t, opt, flags);
	else
		do_printf_di_pn(ptr_n, ptr_t, opt, flags);
	free(ptr_n);
	write(1, ptr_t, opt->len_max);
	flags->count += opt->len_max;
	free(ptr_t);
}

void	start_printf_di(int n, t_flags *flags)
{
	char	*ptr_n;
	t_opts	opt;

	ft_memset(&opt, -1, sizeof(opt));
	if (flags->width < 0)
	{
		flags->isminus = 1;
		flags->width *= -1;
	}
	opt.minus = (n < 0) ? 1 : 0;
	ptr_n = ft_itoa(n);
	opt.len_n = ft_strlen(ptr_n);
	opt.len_max = (flags->width > opt.len_n) ? flags->width : opt.len_n;
	opt.len_max = (opt.len_max > flags->prcs + opt.minus) ? opt.len_max :
		flags->prcs + opt.minus;
	if (n == 0 && flags->prcs == 0 && opt.len_max != flags->width)
		opt.len_max = 0;
	do_printf_di(ptr_n, &opt, flags);
}
