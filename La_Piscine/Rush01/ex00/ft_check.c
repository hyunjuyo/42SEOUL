/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 06:04:19 by jungwkim          #+#    #+#             */
/*   Updated: 2020/11/29 06:04:45 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check_up(int (*square)[4], int value, int i)
{
	int count;
	int max;
	int n;

	count = 1;
	max = square[0][i];
	n = 1;
	while (n < 4)
	{
		if (max < square[n][i])
		{
			max = square[n][i];
			count++;
		}
		n++;
	}
	if (count != value)
		return (0);
	return (1);
}

int		check_down(int (*square)[4], int value, int i)
{
	int count;
	int max;
	int n;

	count = 1;
	max = square[3][i];
	n = 3;
	while (n >= 0)
	{
		if (max < square[n][i])
		{
			max = square[n][i];
			count++;
		}
		n--;
	}
	if (count != value)
		return (0);
	return (1);
}

int		check_left(int (*square)[4], int value, int i)
{
	int count;
	int max;
	int n;

	count = 1;
	n = 1;
	max = square[i][0];
	while (n < 4)
	{
		if (max < square[i][n])
		{
			max = square[i][n];
			count++;
		}
		n++;
	}
	if (count != value)
		return (0);
	return (1);
}

int		check_right(int (*square)[4], int value, int i)
{
	int count;
	int max;
	int n;

	count = 1;
	max = square[i][3];
	n = 3;
	while (n >= 0)
	{
		if (max < square[i][n])
		{
			max = square[i][n];
			count++;
		}
		n--;
	}
	if (count != value)
		return (0);
	return (1);
}
