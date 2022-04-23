/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 16:54:04 by hyunjuyo          #+#    #+#             */
/*   Updated: 2022/02/04 17:32:09 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int				i;
	int				sign;
	unsigned long	num;

	num = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num *= 10;
		num += str[i] - '0';
		i++;
	}
	return (num * sign);
}

void	do_sleep(int sleep_time)
{
	int	zerotime;

	zerotime = check_time();
	while ((check_time() - zerotime) < sleep_time)
		usleep(200);
}

void	do_usleep(int usleep_time)
{
	int	zerotime;

	zerotime = check_time_usec();
	while ((check_time_usec() - zerotime) < usleep_time)
		usleep(10);
}
