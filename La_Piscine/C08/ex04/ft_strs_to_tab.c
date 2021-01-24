/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 19:26:07 by hyunjuyo          #+#    #+#             */
/*   Updated: 2020/12/09 10:58:41 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int					av_size(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char				*av_copy(char *str)
{
	char	*arr;
	int		i;

	arr = (char *)malloc(av_size(str) + 1);
	if (arr == '\0')
		return (0);
	i = -1;
	while (str[++i] != '\0')
		arr[i] = str[i];
	arr[i] = '\0';
	return (arr);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*ptr;

	ptr = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (ptr == '\0')
		return (0);
	i = -1;
	while (++i < ac)
	{
		ptr[i].size = av_size(av[i]);
		ptr[i].str = av[i];
		ptr[i].copy = av_copy(av[i]);
	}
	ptr[i].str = 0;
	return (ptr);
}
