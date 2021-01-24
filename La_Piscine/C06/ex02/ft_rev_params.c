/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 18:37:21 by hyunjuyo          #+#    #+#             */
/*   Updated: 2020/12/03 18:40:56 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int num;
	int i;

	num = argc;
	while (--num > 0)
	{
		i = -1;
		while (argv[num][++i])
			write(1, &argv[num][i], 1);
		write(1, "\n", 1);
	}
	return (0);
}
