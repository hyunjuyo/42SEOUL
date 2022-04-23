/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:01:40 by hyunjuyo          #+#    #+#             */
/*   Updated: 2022/02/04 17:31:57 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_take_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->n_forks[philo->l_fork]);
	print_time_status(philo, 0);
	pthread_mutex_lock(&philo->info->n_forks[philo->r_fork]);
	print_time_status(philo, 0);
}

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex);
	philo->eat_time = check_time();
	print_time_status(philo, 1);
	do_sleep(philo->info->n_time_e);
	philo->eat_count++;
	if (philo->eat_count >= philo->info->n_count)
	{
		philo->info->musteat_philo_count++;
		if (philo->info->musteat_philo_count >= philo->info->n_num)
			philo->info->flag_continue = 0;
	}
	pthread_mutex_unlock(&philo->mutex);
}

void	philo_sleep(t_philo *philo)
{
	print_time_status(philo, 2);
	do_sleep(philo->info->n_time_s);
	print_time_status(philo, 3);
}

void	*do_philo(void *ph)
{
	t_philo	*a_philo;

	a_philo = (t_philo *)ph;
	while (a_philo->info->flag_continue)
	{
		philo_take_fork(a_philo);
		philo_eat(a_philo);
		pthread_mutex_unlock(&a_philo->info->n_forks[a_philo->r_fork]);
		pthread_mutex_unlock(&a_philo->info->n_forks[a_philo->l_fork]);
		philo_sleep(a_philo);
		usleep(50);
	}
	return (NULL);
}
