/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ntow.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 11:20:49 by hyunjuyo          #+#    #+#             */
/*   Updated: 2020/12/06 17:52:04 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_ntow(char *num[])
{
	int		fd;
	char	dict_buf[BUFSIZE];

	fd = open("numbers.dict", O_RDONLY);
	if (fd == -1)
	{
		write(1, "Dict Error\n", 11);
		return ;
	}
	read(fd, dict_buf, sizeof(dict_buf));
	close(fd);
	if (ft_dict_check(dict_buf) != 1)
	{
		write(1, "Dict Error\n", 11);
		return ;
	}
	ft_convert_num(dict_buf, &(*num));
}
