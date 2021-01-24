/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 22:01:27 by hyunjuyo          #+#    #+#             */
/*   Updated: 2020/12/02 10:02:14 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_uppercase(char *str)
{
	int i;
	int count;

	count = 0;
	i = -1;
	while (str[++i] != '\0')
	{
		if (!(str[i] >= 'A' && str[i] <= 'Z'))
			count++;
	}
	if (count > 0)
		return (0);
	return (1);
}
