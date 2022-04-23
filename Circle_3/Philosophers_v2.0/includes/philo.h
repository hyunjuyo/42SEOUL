/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 15:38:18 by hyunjuyo          #+#    #+#             */
/*   Updated: 2022/02/04 17:31:53 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdlib.h>

typedef struct s_philo
{
	int				id;
	int				l_fork;
	int				r_fork;
	int				eat_count;
	int				eat_time;
	int				flag_musteat;
	pthread_mutex_t	mutex;
	pthread_t		tid;
	struct s_info	*info;
}					t_philo;

typedef struct s_info
{
	int				n_num;
	int				n_time_d;
	int				n_time_e;
	int				n_time_s;
	int				n_count;
	int				start_time;
	int				flag_continue;
	int				musteat_philo_count;
	pthread_mutex_t	*n_forks;
	pthread_mutex_t	mutex;
	t_philo			*n_philos;
}					t_info;

int		ft_atoi(const char *str);
int		check_time(void);
int		check_time_usec(void);
int		free_n_destroy(t_info *info);
void	*do_philo(void *ph);
void	print_time_status(t_philo *philo, int type);
void	do_sleep(int sleep_time);
void	do_usleep(int usleep_time);
void	*observer(void *ph);

#endif
