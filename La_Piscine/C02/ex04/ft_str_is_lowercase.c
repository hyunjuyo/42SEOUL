/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 22:22:13 by hyunjuyo          #+#    #+#             */
/*   Updated: 2020/12/02 10:01:28 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_lowercase(char *str)
{
	int i;
	int count;

	count = 0;
	i = -1;
	while (str[++i] != '\0')
	{
		if (!(str[i] >= 'a' && str[i] <= 'z'))
			count++;
	}
	if (count > 0)
		return (0);
	return (1);
}
