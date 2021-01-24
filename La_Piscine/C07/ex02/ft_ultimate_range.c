/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 10:14:52 by hyunjuyo          #+#    #+#             */
/*   Updated: 2020/12/08 20:58:37 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int i;
	int count;

	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	count = max - min;
	*range = (int *)malloc(count * sizeof(int));
	if (*range == '\0')
		return (-1);
	i = 0;
	while (min + i < max)
	{
		(*range)[i] = min + i;
		i++;
	}
	return (count);
}
