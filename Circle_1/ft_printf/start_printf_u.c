/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_printf_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 22:10:54 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/01/19 17:49:06 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	do_printf_u_basic(char *ptr_n, char *ptr_t, t_opts *opt)
{
	int	i;

	i = -1;
	while (++i < opt->len_max - opt->len_n)
		ptr_t[i] = ' ';
	i--;
	while (++i < opt->len_max)
		ptr_t[i] = ptr_n[i - (opt->len_max - opt->len_n)];
}

void	do_printf_u_py(char *ptr_n, char *ptr_t, t_opts *opt, t_flags *flags)
{
	int	i;

	if (ptr_n[0] == '0' && ptr_n[1] == '\0' && flags->prcs == 0)
		opt->len_prcs = 0;
	if (flags->isminus == 1)
	{
		i = -1;
		while (++i < opt->len_prcs)
			ptr_t[i] = ptr_n[i];
		while (i < opt->len_max)
			ptr_t[i++] = ' ';
	}
	else
	{
		i = -1;
		while (++i < opt->len_max - opt->len_prcs)
			ptr_t[i] = ' ';
		i--;
		while (++i < opt->len_max)
			ptr_t[i] = ptr_n[i - (opt->len_max - opt->len_prcs)];
	}
}

void	do_printf_u_pn(char *ptr_n, char *ptr_t, t_opts *opt, t_flags *flags)
{
	int	i;

	if (flags->isminus == 1)
	{
		i = -1;
		while (++i < opt->len_n)
			ptr_t[i] = ptr_n[i];
		while (i < opt->len_max)
			ptr_t[i++] = ' ';
	}
	else if (flags->iszero == 1)
	{
		i = -1;
		while (++i < opt->len_max - opt->len_n)
			ptr_t[i] = '0';
		i--;
		while (++i < opt->len_max)
			ptr_t[i] = ptr_n[i - (opt->len_max - opt->len_n)];
	}
	else
		do_printf_u_basic(ptr_n, ptr_t, opt);
}

void	do_printf_u(char *ptr_n, t_opts *opt, t_flags *flags)
{
	char	*ptr_t;
	char	*temp;
	int		i;

	ptr_t = malloc(sizeof(char) * opt->len_max);
	opt->len_prcs = (flags->prcs > opt->len_n) ? flags->prcs : opt->len_n;
	temp = malloc(sizeof(char) * opt->len_prcs);
	i = -1;
	while (++i < opt->len_prcs - opt->len_n)
		temp[i] = '0';
	i--;
	while (++i < opt->len_prcs)
		temp[i] = ptr_n[i - (opt->len_prcs - opt->len_n)];
	free(ptr_n);
	ptr_n = temp;
	if (flags->prcs >= 0)
		do_printf_u_py(ptr_n, ptr_t, opt, flags);
	else
		do_printf_u_pn(ptr_n, ptr_t, opt, flags);
	free(ptr_n);
	write(1, ptr_t, opt->len_max);
	flags->count += opt->len_max;
	free(ptr_t);
}

void	start_printf_u(unsigned int n, t_flags *flags)
{
	char	*ptr_n;
	t_opts	opt;

	ft_memset(&opt, -1, sizeof(opt));
	if (flags->width < 0)
	{
		flags->isminus = 1;
		flags->width *= -1;
	}
	ptr_n = ft_utoa(n);
	opt.len_n = ft_strlen(ptr_n);
	opt.len_max = (flags->width > opt.len_n) ? flags->width : opt.len_n;
	opt.len_max = (opt.len_max > flags->prcs) ? opt.len_max :
		flags->prcs;
	if (n == 0 && flags->prcs == 0 && opt.len_max != flags->width)
		opt.len_max = 0;
	do_printf_u(ptr_n, &opt, flags);
}
