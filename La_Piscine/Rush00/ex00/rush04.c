/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 17:31:32 by hyunjuyo          #+#    #+#             */
/*   Updated: 2020/11/21 18:45:08 by hyunjuyo         ###   ########.fr       */
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
			if ((!i && !j) || (i != 0 && j != 0 && i == y - 1 && j == x - 1))
				ft_putchar('A');
			else if ((i == 0 && j == x - 1) || (i == y - 1 && j == 0))
				ft_putchar('C');
			else if ((i >= 1 && i < y - 1) && (j >= 1 && j < x - 1))
				ft_putchar(' ');
			else
				ft_putchar('B');
		}
		ft_putchar('\n');
	}
}
