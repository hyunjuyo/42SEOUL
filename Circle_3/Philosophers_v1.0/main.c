/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 17:55:32 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/07/06 19:09:51 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>

int	main(void)
{
	struct timeval	time1;
	int				sec1;
	int				sec2;
	int				usec1;
	int				usec2;
	int				diff_sec;
	int				diff_usec;

	gettimeofday(&time1, NULL);
	sec1 = time1.tv_sec;
	usec1 = time1.tv_usec;
	printf("sec : %ld, usec : %06d\n", time1.tv_sec, time1.tv_usec);
	usleep(2 * 1000 * 1000);
	gettimeofday(&time1, NULL);
	sec2 = time1.tv_sec;
	usec2 = time1.tv_usec;
	printf("sec : %ld, usec : %06d\n", time1.tv_sec, time1.tv_usec);
	diff_sec = sec2 - sec1;
	diff_usec = usec2 - usec1;
	printf("[diff] sec.usec : %d.%06d\n", diff_sec, diff_usec);
	return (0);
}
