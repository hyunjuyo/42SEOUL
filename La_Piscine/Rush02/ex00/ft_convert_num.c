/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_num.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 16:27:05 by hyunjuyo          #+#    #+#             */
/*   Updated: 2020/12/06 13:25:23 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_convert_num(char *dict_buf, char *num[])
{
	int		i;
	char	*where_line;
	char	*start;

	if (ft_strstr(dict_buf, *num) == '\0')
	{
		write(1, "Dict Error\n", 11);
		return ;
	}
	where_line = ft_strstr(dict_buf, *num);
	i = 1;
	while (*(where_line + i) != ':')
		i++;
	start = where_line + i + 1;
	ft_write_word(start);
	write(1, "\n", 1);
}
