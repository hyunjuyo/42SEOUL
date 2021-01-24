/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 15:31:10 by hyunjuyo          #+#    #+#             */
/*   Updated: 2020/12/06 12:28:41 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_dict_check(char *dict_buf)
{
	int i;
	int count_c;
	int check;

	count_c = 0;
	check = 0;
	i = -1;
	while (dict_buf[++i] != '\0')
	{
		if (dict_buf[i] == ':')
		{
			count_c++;
			if (count_c > 1)
				return (0);
		}
		if (dict_buf[i] == '\n')
			count_c = 0;
	}
	return (1);
}
