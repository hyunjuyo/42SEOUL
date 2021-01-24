/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 19:26:07 by hyunjuyo          #+#    #+#             */
/*   Updated: 2020/12/09 11:01:43 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <unistd.h>

void	write_str(char *str)
{
	int i;

	i = -1;
	while (str[++i] != '\0')
		write(1, &str[i], 1);
}

void	write_size(int nb)
{
	int		div;
	int		mod;
	char	num;

	div = nb / 10;
	mod = nb % 10;
	if (div > 0)
		write_size(div);
	num = mod + '0';
	write(1, &num, 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int i;

	i = -1;
	while (par[++i].str != '\0')
	{
		write_str(par[i].str);
		write(1, "\n", 1);
		write_size(par[i].size);
		write(1, "\n", 1);
		write_str(par[i].copy);
		write(1, "\n", 1);
	}
}
