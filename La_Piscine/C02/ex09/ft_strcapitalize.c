/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 23:47:30 by hyunjuyo          #+#    #+#             */
/*   Updated: 2020/12/02 10:33:42 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		is_word(char *arr)
{
	if (arr[0] >= '0' && arr[0] <= '9')
		return (1);
	else if (arr[0] >= 'a' && arr[0] <= 'z')
		return (1);
	else if (arr[0] >= 'A' && arr[0] <= 'Z')
		return (1);
	else
		return (0);
}

char	*ft_strcapitalize(char *str)
{
	int i;

	i = -1;
	while (str[++i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
	}
	if (str[0] >= 'a' && str[0] <= 'z')
		str[0] = str[0] - 32;
	i = -1;
	while (str[++i] != '\0')
	{
		if (is_word(str + i) != 1)
		{
			if (str[i + 1] >= 'a' && str[i + 1] <= 'z')
				str[i + 1] = str[i + 1] - 32;
		}
	}
	return (str);
}
