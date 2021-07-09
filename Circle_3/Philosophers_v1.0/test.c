/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 16:33:28 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/07/09 16:40:43 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

void	*function(void *data)
{
	int	i;

	printf("start~!!\n");
	printf("before temp_num : %d\n", *(int *)data);
	i = -1;
	while (++i < 10)
		(*(int *)data)++;
	printf("after temp_num : %d\n", *(int *)data);
	return (void *)0;
}

int	main(void)
{
	pthread_t	tid1;
	pthread_t	tid2;
	pthread_t	tid3;
	int			num;

	num = 0;
	pthread_create(&tid1, NULL, function, (void *)&num);
	pthread_create(&tid2, NULL, function, (void *)&num);
	pthread_create(&tid3, NULL, function, (void *)&num);
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	pthread_join(tid3, NULL);
	printf("num : %d\n", num);
	return (0);
}
