/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 22:09:12 by hyunjuyo          #+#    #+#             */
/*   Updated: 2020/11/29 19:55:38 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_len(int nb)
{
	int len;

	len = 0;
	while (nb != 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

void	ft_putchars(int nb)
{
	int		len;
	char	arr[11];
	int		i;

	len = ft_len(nb);
	i = len;
	while (--i >= 0)
	{
		arr[i] = '0' + nb % 10;
		nb = nb / 10;
	}
	i = -1;
	while (++i < len)
		write(1, arr + i, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	else if (nb == 0)
	{
		write(1, "0", 1);
		return ;
	}
	else if (nb < 0)
	{
		write(1, "-", 1);
		nb = nb * -1;
	}
	ft_putchars(nb);
}
