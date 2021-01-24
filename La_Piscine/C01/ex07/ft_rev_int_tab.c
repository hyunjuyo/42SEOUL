/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 22:46:06 by hyunjuyo          #+#    #+#             */
/*   Updated: 2020/11/30 14:17:35 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int temp;
	int i;

	i = -1;
	while (++i < size / 2)
	{
		temp = *(tab + i);
		*(tab + i) = *(tab + (size - 1) - i);
		*(tab + (size - 1) - i) = temp;
	}
}
