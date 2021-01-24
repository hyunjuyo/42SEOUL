/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 21:31:23 by hyunjuyo          #+#    #+#             */
/*   Updated: 2020/12/07 10:54:10 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int num;

	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	else
	{
		num = nb;
		while (--power > 0)
			num *= nb;
	}
	return (num);
}
