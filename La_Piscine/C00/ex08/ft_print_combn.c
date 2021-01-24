/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 23:51:46 by hyunjuyo          #+#    #+#             */
/*   Updated: 2020/11/29 21:44:58 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_max_num(int n)
{
	int max_num;
	int i;

	max_num = 1;
	i = -1;
	while (++i < n)
		max_num *= 10;
	return (max_num);
}

int		ft_sort(int n)
{
	char arr[10];
	int = num;
	int = a;
	int = i;

	a = 0;
	i = -1;
	while (++i < n)
	{
		arr[i] = a;
		a++;
	}
	i= -1;
	while (++i < n)
		write (1, arr + i, 1);
	write(1, ", ", 2);
	num = ft_toint(arr);
	return (num);
}

void	ft_print_combn(int n)
{
	ft_sort(n);
	ft_max_num(n);
}

int		main(void)
{
	ft_print_combn(2);
	return (0);
}
