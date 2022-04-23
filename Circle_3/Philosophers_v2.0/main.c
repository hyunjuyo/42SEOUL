/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 17:55:32 by hyunjuyo          #+#    #+#             */
/*   Updated: 2022/02/04 17:31:59 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_info(int argc, char *argv[], t_info *info)
{
	info->n_num = ft_atoi(argv[1]);
	info->n_time_d = ft_atoi(argv[2]);
	info->n_time_e = ft_atoi(argv[3]);
	info->n_time_s = ft_atoi(argv[4]);
	info->flag_continue = 1;
	info->musteat_philo_count = 0;
	if (info->n_num < 1 || info->n_time_d < 0 || info->n_time_e < 0 || \
		info->n_time_s < 0)
		return (-1);
	if (info->n_time_d == 0)
	{
		printf("%d %d died\n", 0, 1);
		return (-1);
	}
	if (argc == 6)
	{
		info->n_count = ft_atoi(argv[5]);
		if (info->n_count < 0)
			return (-1);
	}
	else
		info->n_count = 99999;
	return (0);
}

int	init_philos(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->n_num)
	{
		info->n_philos[i].id = i + 1;
		info->n_philos[i].l_fork = i;
		info->n_philos[i].r_fork = (i + 1) % info->n_num;
		info->n_philos[i].eat_count = 0;
		info->n_philos[i].eat_time = -1;
		info->n_philos[i].flag_musteat = 0;
		info->n_philos[i].info = info;
		if (pthread_mutex_init(&(info->n_philos[i].mutex), NULL) == -1)
			return (-1);
		if (pthread_mutex_init(&(info->n_forks[i]), NULL) == -1)
			return (-1);
	}
	if (pthread_mutex_init(&(info->mutex), NULL))
		return (-1);
	return (0);
}

void	do_pthread(t_info *info, int i)
{
	pthread_t	tid;

	info->n_philos[i].eat_time = check_time();
	pthread_create(&tid, NULL, do_philo, (void *)&info->n_philos[i]);
	pthread_detach(tid);
	pthread_create(&info->n_philos[i].tid, NULL, observer, \
			(void *)&info->n_philos[i]);
	usleep(20);
}

int	main(int argc, char *argv[])
{
	t_info		info;
	int			i;

	if (!(argc == 5 || argc == 6) || check_info(argc, argv, &info) == -1)
		return (0);
	info.n_philos = malloc(sizeof(t_philo) * info.n_num);
	info.n_forks = malloc(sizeof(pthread_mutex_t) * info.n_num);
	if (init_philos(&info) == -1)
	{
		free_n_destroy(&info);
		return (0);
	}
	info.start_time = check_time();
	i = -1;
	while (++i < info.n_num)
		do_pthread(&info, i);
	i = -1;
	while (++i < info.n_num)
		pthread_join(info.n_philos[i].tid, NULL);
	free_n_destroy(&info);
	return (0);
}
