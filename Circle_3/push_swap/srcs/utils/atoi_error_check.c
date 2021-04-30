/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_error_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 16:20:59 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/04/30 16:35:57 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_error_int1(t_atoi_info *info, unsigned int num)
{
	if (num < info->temp)
		print_error("Error", 1);
}

void	check_error_int2(t_atoi_info *info, char *str, unsigned int num)
{
	if (info->check == 0 || (int)ft_strlen(str) != info->i)
		print_error("Error", 1);
	if (info->sign == 1 && num > 2147483647)
		print_error("Error", 1);
	if (info->sign == -1 && num > 2147483648)
		print_error("Error", 1);
}

int		atoi_error_check(char *str)
{
	t_atoi_info		info;
	unsigned int	num;

	num = 0;
	ft_memset(&info, 0, sizeof(t_atoi_info));
	info.sign = 1;
	while ((str[info.i] >= 9 && str[info.i] <= 13) || str[info.i] == ' ')
		info.i++;
	if (str[info.i] == '+' || str[info.i] == '-')
	{
		if (str[info.i] == '-')
			info.sign *= -1;
		info.i++;
	}
	while (str[info.i] >= '0' && str[info.i] <= '9')
	{
		info.check++;
		info.temp = num;
		num *= 10;
		num += str[info.i] - '0';
		check_error_int1(&info, num);
		info.i++;
	}
	check_error_int2(&info, str, num);
	return (num * info.sign);
}
