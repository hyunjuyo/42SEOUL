/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 11:22:18 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/01/17 00:26:50 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_len_u(unsigned int n, int base)
{
	int len;

	if (n == 0)
		return (1);
	len = 0;
	while (n > 0)
	{
		len++;
		n = n / base;
	}
	return (len);
}

static void	ft_utoa_start(char *ptr, int *i, unsigned int n)
{
	if (n / 10 > 0)
		ft_utoa_start(ptr, i, n / 10);
	ptr[*i] = n % 10 + '0';
	*i += 1;
}

char		*ft_utoa(unsigned int n)
{
	char		*ptr;
	int			i;

	if (!(ptr = malloc(sizeof(char) * (ft_len_u(n, 10) + 1))))
		return (0);
	i = 0;
	ft_utoa_start(ptr, &i, n);
	ptr[i] = '\0';
	return (ptr);
}

void		toupper_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
}

char		*ft_utoa_hex(unsigned int n)
{
	char		*ptr;
	int			i;

	if (!(ptr = malloc(sizeof(char) * (ft_len_u(n, 16) + 1))))
		return (0);
	i = 0;
	convert_to_hex(n, ptr, &i);
	ptr[i] = '\0';
	return (ptr);
}
