/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 17:55:32 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/07/09 17:48:29 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

int	num;

void	*philo_thread(void *data)
{
	struct timeval	cur_time;
	int	i;

	pthread_mutex_lock(&mutex_lock);
	gettimeofday(&cur_time, NULL);
	printf("%ld.%06d %s is eating\n", cur_time.tv_sec, cur_time.tv_usec, (char *)data);
	usleep(2 * 1000 * 1000);
	i = -1;
	while (++i < 10000)
		num++;
	printf("%s num : %d\n", (char *)data, num);
	gettimeofday(&cur_time, NULL);
	printf("%ld.%06d %s is sleeping\n", cur_time.tv_sec, cur_time.tv_usec, (char *)data);
	pthread_mutex_unlock(&mutex_lock);
	return (void *)0;
}
/*
pthread_t	*create_forks(int num_of_philos)
{
	pthread_t	*temp_tid;



	return 
}
*/

int	main(int argc, char *argv[])
{
	pthread_t		tid1;
	pthread_t		tid2;
	pthread_t		tid3;
	int				num_of_philos;
	
	num = 0;
	if (argc < 2)
	{
		printf("argc is 1\n");
		return (0);
	}
	num_of_philos = ft_atoi(argv[1]);
	pthread_mutex_init(&mutex_lock, NULL);
//	tid = create_forks(num_of_philos);
//	printf("num_of_philos : %d\n", num_of_philos);  //test
	pthread_create(&tid1, NULL, philo_thread, (void *)"1");
	pthread_create(&tid2, NULL, philo_thread, (void *)"2");
	pthread_create(&tid3, NULL, philo_thread, (void *)"3");
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	pthread_join(tid3, NULL);
	printf("Last line~\n");
	return (0);
}
