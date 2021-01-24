/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 18:00:34 by hyunjuyo          #+#    #+#             */
/*   Updated: 2020/11/29 19:54:46 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_write(int a, int b)
{
	int arr[5];
	int ten;
	int one;
	int i;

	i = -1;
	while (++i < 2)
	{
		if (i == 0)
		{
			ten = '0' + a / 10;
			one = '0' + a % 10;
		}
		else if (i == 1)
		{
			ten = '0' + b / 10;
			one = '0' + b % 10;
		}
		arr[i * 3] = ten;
		arr[i * 3 + 1] = one;
	}
	arr[2] = ' ';
	i = -1;
	while (++i < 5)
		write(1, arr + i, 1);
}

void	ft_print_comb2(void)
{
	int a;
	int b;

	a = -1;
	while (++a < 98)
	{
		b = a;
		while (++b <= 99)
		{
			ft_write(a, b);
			write(1, ", ", 2);
		}
	}
	ft_write(a, --b);
}
