/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 11:22:52 by hyunjuyo          #+#    #+#             */
/*   Updated: 2020/12/03 00:50:16 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putstr_non_printable(char *str)
{
	int		i;
	char	div;
	char	mod;

	i = -1;
	while (str[++i] != '\0')
	{
		if (str[i] >= 32 && str[i] <= 126)
			write(1, str + i, 1);
		else if (!(str[i] >= 32 && str[i] <= 126))
		{
			div = str[i] / 16 + '0';
			mod = str[i] % 16 - 10 + 'a';
			write(1, "\\", 1);
			write(1, &div, 1);
			write(1, &mod, 1);
		}
	}
}
