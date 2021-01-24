/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 21:44:23 by hyunjuyo          #+#    #+#             */
/*   Updated: 2020/12/02 09:58:16 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_alpha(char *str)
{
	int i;
	int count;
	int result;

	result = 0;
	count = 0;
	i = -1;
	while (str[++i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			count++;
		else if (str[i] >= 'a' && str[i] <= 'z')
			count++;
	}
	if (i == 0 || i == count)
		result = 1;
	return (result);
}
