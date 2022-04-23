/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 18:29:03 by hyunjuyo          #+#    #+#             */
/*   Updated: 2022/02/04 17:32:12 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_time_usec(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_usec);
}

int	check_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	mutex_destroy(t_info *info)
{
	int	i;

	if (!info)
		return (-1);
	else
	{
		if (info->n_philos)
		{
			i = -1;
			while (++i < info->n_num)
				pthread_mutex_destroy(&(info->n_philos[i].mutex));
		}
		if (info->n_forks)
		{
			i = -1;
			while (++i < info->n_num)
				pthread_mutex_destroy(&(info->n_forks[i]));
		}
		if (info->n_philos && info->n_forks)
			pthread_mutex_destroy(&(info->mutex));
	}
	return (0);
}

int	free_n_destroy(t_info *info)
{
	if (!info)
		return (-1);
	else
	{
		if (info->n_philos)
		{
			free(info->n_philos);
			info->n_philos = NULL;
		}
		if (info->n_forks)
		{
			free(info->n_forks);
			info->n_forks = NULL;
		}
		mutex_destroy(info);
	}
	return (0);
}

void	print_time_status(t_philo *philo, int type)
{
	pthread_mutex_lock(&philo->info->mutex);
	printf("%d ", check_time() - philo->info->start_time);
	printf("%d ", philo->id);
	if (type == 0)
		printf("has taken a fork\n");
	else if (type == 1)
		printf("is eating\n");
	else if (type == 2)
		printf("is sleeping\n");
	else if (type == 3)
		printf("is thinking\n");
	else
	{
		printf("died\n");
		philo->info->flag_continue = 0;
	}
	pthread_mutex_unlock(&philo->info->mutex);
}
