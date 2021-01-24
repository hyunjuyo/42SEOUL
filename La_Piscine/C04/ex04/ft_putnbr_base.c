/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 10:07:18 by hyunjuyo          #+#    #+#             */
/*   Updated: 2020/12/05 13:54:04 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		base_count(char *base, int base_num)
{
	int start;
	int i;
	int count;

	start = 0;
	count = 1;
	while (base[start] != '\0')
	{
		i = 1;
		while (start + i < base_num)
		{
			if (base[start] == base[start + i])
				count++;
			i++;
		}
		start++;
	}
	return (count);
}

int		chk_base(char *base)
{
	int base_num;

	base_num = 0;
	while (base[base_num] != '\0')
	{
		if (base[base_num] == '+' || base[base_num] == '-')
			return (0);
		base_num++;
	}
	if (base_count(base, base_num) != 1)
		return (0);
	return (base_num);
}

void	write_base(unsigned int nbr, int base_num, char *base)
{
	unsigned int div;
	unsigned int mod;

	div = nbr / base_num;
	mod = nbr % base_num;
	if (div != 0)
		write_base(div, base_num, base);
	write(1, base + mod, 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		base_num;

	base_num = chk_base(base);
	if (base_num < 2)
		return ;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr *= -1;
	}
	write_base(nbr, base_num, base);
}
