/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 22:06:10 by hyunjuyo          #+#    #+#             */
/*   Updated: 2020/12/02 10:06:46 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_printable(char *str)
{
	int i;
	int count;

	count = 0;
	i = -1;
	while (str[++i] != '\0')
	{
		if (!(str[i] >= 32 && str[i] <= 126))
			count++;
	}
	if (count > 0)
		return (0);
	return (1);
}
