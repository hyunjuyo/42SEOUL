/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 17:25:21 by hyunjuyo          #+#    #+#             */
/*   Updated: 2020/11/29 19:53:22 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchars(char a, char b, char c)
{
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, &c, 1);
}

void	ft_print_comb(void)
{
	char a;
	char b;
	char c;

	a = '0';
	while (a < '7')
	{
		b = a;
		while (++b <= '8')
		{
			c = b;
			while (++c <= '9')
			{
				ft_putchars(a, b, c);
				write(1, ", ", 2);
			}
		}
		a++;
	}
	b--;
	c--;
	ft_putchars(a, b, c);
}
