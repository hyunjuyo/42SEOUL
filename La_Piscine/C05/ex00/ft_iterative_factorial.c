/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 20:30:17 by hyunjuyo          #+#    #+#             */
/*   Updated: 2020/12/07 10:50:49 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int num;

	if (nb < 0)
		return (0);
	else if (nb == 1 || nb == 0)
		return (1);
	else
	{
		num = nb;
		while (nb > 1)
			num *= --nb;
	}
	return (num);
}
