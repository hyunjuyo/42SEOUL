/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 10:41:45 by hyunjuyo          #+#    #+#             */
/*   Updated: 2020/12/06 13:31:19 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	start_write(char *start)
{
	start--;
	while (*(++start) != '\n')
	{
		if (*start >= 32 && *start <= 126)
		{
			if (*start == ' ' || *start == '\t')
			{
				if (*(start + 1) == ' ' || *(start + 1) == '\t')
					continue;
				else
				{
					if (*(start + 1) != '\n')
						write(1, start, 1);
					continue;
				}
			}
			write(1, start, 1);
		}
	}
}

void	ft_write_word(char *start)
{
	start--;
	while (*(++start) != '\n')
	{
		if (*start >= 32 && *start <= 126)
		{
			if (*start == ' ' || *start == '\t')
				continue;
			else
				break ;
		}
	}
	if (*start == '\n')
		write(1, "Dict Error\n", 11);
	start_write(start);
}
