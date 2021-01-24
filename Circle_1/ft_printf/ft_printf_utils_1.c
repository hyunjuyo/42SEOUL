/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 23:59:09 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/01/19 17:40:28 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	convert_to_hex(long long ptr, char *arr, int *i)
{
	char	*arr_h;

	arr_h = "0123456789abcdef";
	if (ptr / 16 > 0)
		convert_to_hex(ptr / 16, arr, i);
	arr[(*i)++] = *(arr_h + ptr % 16);
}

void	*ptr_to_hex(long long ptr)
{
	char	arr[20];
	int		i;

	i = 0;
	convert_to_hex(ptr, arr, &i);
	arr[i] = '\0';
	return (ft_strjoin("0x", arr));
}
