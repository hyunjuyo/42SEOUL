/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 11:20:49 by hyunjuyo          #+#    #+#             */
/*   Updated: 2020/12/06 18:06:02 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		check_num(char *argv[])
{
	int i;
	int count;

	i = -1;
	count = 0;
	while ((*argv)[++i] != '\0')
	{
		if ((*argv)[i] == '-' || (*argv)[i] == '.')
			count++;
	}
	if (i == 0)
		return (1);
	return (count);
}

void	read_entry(void)
{
	int		fd;
	char	dict_buf[BUFSIZE];
	int		i;

	fd = open("numbers.dict", O_RDONLY);
	if (fd == -1)
	{
		write(1, "Dict Error\n", 11);
		return ;
	}
	read(fd, dict_buf, sizeof(dict_buf));
	close(fd);
	i = -1;
	while (dict_buf[++i] != '\0')
		write(1, dict_buf + i, 1);
}

int		main(int argc, char *argv[])
{
	if (argc == 2)
	{
		if (check_num(&argv[1]) > 0)
		{
			write(1, "Error\n", 6);
			return (0);
		}
		ft_ntow(&argv[1]);
	}
	else if (argc == 3)
	{
		if (check_num(&argv[2]) > 0)
		{
			write(1, "Error\n", 6);
			return (0);
		}
		ft_ntow_newdict(&argv[2], &argv[1]);
	}
	else if (argc == 1)
		read_entry();
	else
		write(1, "Error\n", 6);
	return (0);
}
