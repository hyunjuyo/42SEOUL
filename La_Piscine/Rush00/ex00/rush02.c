/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuan <seuan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 18:35:47 by seuan             #+#    #+#             */
/*   Updated: 2020/11/21 19:02:42 by hyunjuyo         ###   ########.fr       */
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
			if (i == 0 && (j == 0 || j == x - 1))
				ft_putchar('A');
			else if (i == y - 1 && (j == 0 || j == x - 1))
				ft_putchar('C');
			else if ((i == 0 || i == y - 1) && (j > 0 && j < x - 1))
				ft_putchar('B');
			else if ((i > 0 && i < y - 1 && (j == 0 || j == x - 1)))
				ft_putchar('B');
			else
				ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}
