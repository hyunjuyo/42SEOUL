/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 22:03:01 by hyunjuyo          #+#    #+#             */
/*   Updated: 2020/12/02 09:59:49 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_numeric(char *str)
{
	int i;
	int result;

	result = 1;
	i = -1;
	while (str[++i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			result = 0;
	}
	return (result);
}
