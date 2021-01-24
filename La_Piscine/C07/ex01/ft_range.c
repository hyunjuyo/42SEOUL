/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 15:51:33 by hyunjuyo          #+#    #+#             */
/*   Updated: 2020/12/08 20:53:53 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_size_check(int min, int max)
{
	int count;

	count = 0;
	while (min + count < max)
		count++;
	return (count);
}

int	*ft_range(int min, int max)
{
	int *arr;
	int count;
	int i;

	if (min >= max)
		return (0);
	count = ft_size_check(min, max);
	arr = (int *)malloc(count * sizeof(int));
	if (arr == '\0')
		return (0);
	i = -1;
	while (++i < count)
	{
		arr[i] = min;
		min++;
	}
	return (arr);
}
