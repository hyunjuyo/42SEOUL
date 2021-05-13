/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 18:37:06 by hyunjuyo          #+#    #+#             */
/*   Updated: 2020/12/29 20:28:38 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len_i(long long n)
{
	int len;

	if (n == 0)
		return (1);
	len = 0;
	while (n > 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

static void	ft_itoa_start(char *ptr, int *i, unsigned int num)
{
	if (num / 10 > 0)
		ft_itoa_start(ptr, i, num / 10);
	ptr[*i] = num % 10 + '0';
	*i += 1;
}

char		*ft_itoa(int n)
{
	long long	num;
	char		*ptr;
	int			minus;
	int			i;

	minus = 0;
	if (n < 0)
	{
		num = n;
		num *= -1;
		minus = 1;
	}
	else
		num = n;
	if (!(ptr = malloc(sizeof(char) * (ft_len_i(num) + minus + 1))))
		return (0);
	i = 0;
	if (minus == 1)
		ptr[i++] = '-';
	ft_itoa_start(ptr, &i, num);
	ptr[i] = '\0';
	return (ptr);
}
