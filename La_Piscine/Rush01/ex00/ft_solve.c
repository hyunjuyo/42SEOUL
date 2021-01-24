/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 05:57:25 by jungwkim          #+#    #+#             */
/*   Updated: 2020/11/29 12:15:23 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		check_up(int (*square)[4], int value, int i);
int		check_down(int (*square)[4], int value, int i);
int		check_left(int (*square)[4], int value, int i);
int		check_right(int (*square)[4], int value, int i);

void	print(int (*square)[4])
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			c = square[i][j] + '0';
			write(1, &c, 1);
			if (j != 3)
				write(1, " ", 1);
			j++;
		}
		i++;
		j = 0;
		write(1, "\n", 1);
	}
}

int		is_valid(int i, int j, int value, int (*square)[4])
{
	int temp;

	temp = 0;
	if (square[i][j] != 0)
		return (0);
	while (temp < 4)
	{
		if (value == square[i][temp])
			return (0);
		temp++;
	}
	temp = 0;
	while (temp < 4)
	{
		if (value == square[temp][j])
			return (0);
		temp++;
	}
	return (1);
}

int		find(int *i, int *j, int (*square)[4])
{
	*i = 0;
	*j = 0;
	while (*i < 4)
	{
		while (*j < 4)
		{
			if (square[*i][*j] == 0)
				return (1);
			*j += 1;
		}
		*i += 1;
		*j = 0;
	}
	return (0);
}

int		check_square(int (*square)[4], int (*arr)[2])
{
	int i;

	i = 0;
	while (i++ < 4)
		if (!(check_up(square, arr[i - 1][0], i - 1)))
			return (0);
	while (i++ < 8)
		if (!(check_down(square, arr[i - 4 - 1][1], i - 4 - 1)))
			return (0);
	while (i++ < 12)
		if (!(check_left(square, arr[i - 4 - 1][0], i - 8 - 1)))
			return (0);
	while (i++ < 16)
		if (!(check_right(square, arr[i - 8 - 1][1], i - 12 - 1)))
			return (0);
	return (1);
}

int		solve(int (*square)[4], int (*arr)[2])
{
	int i;
	int j;
	int cand;

	if (!find(&i, &j, square))
		if (check_square(square, arr))
			return (1);
	cand = 1;
	while (cand <= 4)
	{
		if (is_valid(i, j, cand, square))
		{
			square[i][j] = cand;
			if (solve(square, arr))
				return (1);
			square[i][j] = 0;
		}
		cand++;
	}
	return (0);
}
