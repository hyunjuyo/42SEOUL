/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 23:11:47 by hyunjuyo          #+#    #+#             */
/*   Updated: 2020/11/30 14:19:21 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int temp;
	int start;
	int compr;

	start = -1;
	while (++start < (size - 1))
	{
		compr = 0;
		while (++compr < (size - start))
		{
			temp = *(tab + start);
			if (*(tab + start) > *(tab + start + compr))
			{
				*(tab + start) = *(tab + start + compr);
				*(tab + start + compr) = temp;
			}
		}
	}
}
