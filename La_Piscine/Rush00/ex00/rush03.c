/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannlee <hannlee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 16:40:38 by hannlee           #+#    #+#             */
/*   Updated: 2020/11/21 18:41:56 by hannlee          ###   ########.fr       */
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
			if (!j && (!i || i == y - 1))
				ft_putchar('A');
			else if ((i > 0 && i < y - 1) && (!j || j == x - 1))
				ft_putchar('B');
			else if ((j > 0 && j < x - 1) && (!i || i == y - 1))
				ft_putchar('B');
			else if (j == x - 1 && (!i || i == y - 1))
				ft_putchar('C');
			else
				ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}
