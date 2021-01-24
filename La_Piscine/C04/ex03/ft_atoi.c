/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 23:02:27 by hyunjuyo          #+#    #+#             */
/*   Updated: 2020/12/05 13:50:08 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		ft_result(char *str, int start, int len, int sign)
{
	int i;
	int xten;
	int count;
	int num;
	int result;

	result = 0;
	num = 0;
	i = 0;
	while (i < len)
	{
		count = 1;
		xten = 1;
		while (count < len - i)
		{
			xten *= 10;
			count++;
		}
		num = xten * (str[start + i] - '0');
		result += num;
		i++;
	}
	if (sign % 2 == 1)
		result *= -1;
	return (result);
}

int		is_pass(char *str, int i)
{
	if (str[i] == '\t' || str[i] == '\n' || str[i] == '\v')
		return (1);
	if (str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		return (1);
	if (str[i] == '+' || str[i] == '-')
		return (1);
	return (0);
}

void	sign_chk(char *str, int i, int *start, int *sign)
{
	*start = i + 1;
	if (str[i] == '-')
		*sign += 1;
}

void	len_chk(int *len, int *flag)
{
	*flag = 1;
	*len += 1;
}

int		ft_atoi(char *str)
{
	int i;
	int start;
	int len;
	int sign;
	int flag;

	flag = 0;
	i = -1;
	start = i + 1;
	len = 0;
	sign = 0;
	while (str[++i] != '\0')
	{
		if (flag == 0 && is_pass(str, i) == 1)
			sign_chk(str, i, &start, &sign);
		else if (str[i] >= '0' && str[i] <= '9')
			len_chk(&len, &flag);
		else
			break ;
	}
	return (ft_result(str, start, len, sign));
}
