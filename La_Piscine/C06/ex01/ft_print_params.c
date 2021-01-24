/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 18:23:24 by hyunjuyo          #+#    #+#             */
/*   Updated: 2020/12/03 18:35:51 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int num;
	int i;

	num = 0;
	while (++num < argc)
	{
		i = -1;
		while (argv[num][++i])
			write(1, &argv[num][i], 1);
		write(1, "\n", 1);
	}
	return (0);
}
