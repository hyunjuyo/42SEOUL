/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puzzle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 05:20:13 by jungwkim          #+#    #+#             */
/*   Updated: 2020/11/29 13:10:03 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	start(int (*arr)[2]);

void	input_swap(int arr[][2])
{
	int tmp;
	int col;
	int row;

	col = 4;
	row = 0;
	while (col < 8)
	{
		tmp = arr[col][0];
		arr[col][0] = arr[row][1];
		arr[row][1] = tmp;
		col++;
		row++;
	}
}

void	get_input(char *str, int arr[][2])
{
	int i;
	int first;
	int second;

	i = 0;
	first = 0;
	second = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
		{
			i++;
			continue ;
		}
		arr[first][second] = str[i] - '0';
		first++;
		if (first >= 8)
		{
			second++;
			first = 0;
		}
		i++;
	}
}

int		main(int argc, char *argv[])
{
	char	*str;
	int		i;
	int		j;
	int		arr[8][2];

	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	i = 0;
	j = 0;
	while (i++ < 8)
	{
		while (j < 2)
			arr[i - 1][j++] = -1;
		j = 0;
	}
	str = argv[1];
	get_input(str, arr);
	input_swap(arr);
	start(arr);
	return (0);
}
