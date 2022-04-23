/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:03:15 by hyunjuyo          #+#    #+#             */
/*   Updated: 2022/02/04 17:32:06 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*observer(void *ph)
{
	t_philo	*a_philo;

	a_philo = (t_philo *)ph;
	while (a_philo->info->flag_continue)
	{
		if (check_time() - a_philo->eat_time > a_philo->info->n_time_d)
		{
			print_time_status(a_philo, 9);
			return (NULL);
		}
		usleep(5000);
	}
	return (NULL);
}
