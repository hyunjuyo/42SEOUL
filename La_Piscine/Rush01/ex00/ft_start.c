/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 05:41:18 by jungwkim          #+#    #+#             */
/*   Updated: 2020/11/29 14:47:07 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int		solve(int (*square)[4], int (*arr)[2]);
void	print(int (*square)[4]);

void	create_square(int (*square)[4])
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			square[i][j] = 0;
			j++;
		}
		i++;
		j = 0;
	}
}

void	ft_put_first(int (*square)[4], int i, int a, int b)
{
	int n;
	int m;

	n = 0;
	m = 0;
	if ((a == 4 && b == 1) || (a == 1 && b == 4))
	{
		while (n < 4)
		{
			n = a > b ? n : 3 - n;
			square[n++][i] = (m++) + 1;
		}
	}
	else if ((a == 3 && b == 2) || (a == 2 && b == 3) || (a == 3 && b == 1))
		square[4 - b][i] = 4;
	else if ((a = 1 && b == 3))
		square[0][i] = 4;
	else if ((a == 2 && b == 1) || (a == 1 && b == 2))
	{
		n = a > b ? n : 3 - n;
		square[n][i] = 3;
		square[3 - n][i] = 4;
	}
}

void	ft_put_second(int (*square)[4], int i, int a, int b)
{
	int n;
	int m;

	n = 0;
	m = 0;
	if ((a == 4 && b == 1) || (a == 1 && b == 4))
	{
		while (n < 4)
		{
			n = a > b ? n : 3 - n;
			square[i][n++] = (m++) + 1;
		}
	}
	else if ((a == 3 && b == 2) || (a == 2 && b == 3) || (a == 3 && b == 1))
		square[i][4 - b] = 4;
	else if ((a == 1 && b == 3))
		square[i][0] = 4;
	else if ((a == 2 && b == 1) || (a == 1 && b == 2))
	{
		n = a > b ? n : 3 - n;
		square[i][n] = 3;
		square[i][3 - n] = 4;
	}
}

void	ft_first_loop(int (*square)[4], int (*arr)[2])
{
	int i;

	i = 0;
	while (i < 4)
	{
		ft_put_first(square, i, arr[i][0], arr[i][1]);
		i++;
	}
	while (i < 8)
	{
		ft_put_second(square, i - 4, arr[i][0], arr[i][1]);
		i++;
	}
}

void	start(int (*arr)[2])
{
	int (*square)[4];

	square = (int (*)[4])malloc(4 * 4 * 4);
	create_square(square);
	ft_first_loop(square, arr);
	if (solve(square, arr))
		print(square);
	else
		write(1, "Error\n", 6);
	free(square);
}
