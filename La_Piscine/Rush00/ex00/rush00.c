/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannlee <hannlee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 11:24:12 by hannlee           #+#    #+#             */
/*   Updated: 2020/11/21 18:41:34 by hannlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

extern void		ft_putchar(char c);

void			rush(int x, int y)
{
	int i;
	int j;

	i = -1;
	while (++i < y)
	{
		j = -1;
		while (++j < x)
		{
			if ((j == 0 || j == x - 1) && (i == 0 || i == y - 1))
				ft_putchar('o');
			else if ((j > 0 && j < x - 1) && (i == 0 || i == y - 1))
				ft_putchar('-');
			else if ((i > 0 && i < y - 1 && (j == 0 || j == x - 1)))
				ft_putchar('|');
			else
				ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}
