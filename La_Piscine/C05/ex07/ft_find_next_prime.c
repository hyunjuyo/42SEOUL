/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 21:26:44 by hyunjuyo          #+#    #+#             */
/*   Updated: 2020/12/07 15:19:32 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_find_next_prime(int nb)
{
	long long	i;
	int			count;

	while (nb <= 1)
		nb++;
	while (1)
	{
		count = 0;
		i = 1;
		while (i * i <= nb)
		{
			if (nb % i == 0)
				count++;
			i++;
		}
		if (count == 1)
			return (nb);
		nb++;
	}
	return (0);
}
