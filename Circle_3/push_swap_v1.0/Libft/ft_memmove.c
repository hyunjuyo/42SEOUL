/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 10:38:12 by hyunjuyo          #+#    #+#             */
/*   Updated: 2020/12/29 21:47:12 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*ptr_d;
	unsigned char	*ptr_s;
	long long		i;
	int				n;

	if (!dst && !src)
		return (0);
	ptr_d = (unsigned char *)dst;
	ptr_s = (unsigned char *)src;
	if (dst < src)
		n = 1;
	else
	{
		n = -1;
		ptr_d = ptr_d + len - 1;
		ptr_s = ptr_s + len - 1;
	}
	i = -1;
	while (++i < (long long)len)
	{
		*ptr_d = *ptr_s;
		ptr_d = ptr_d + n;
		ptr_s = ptr_s + n;
	}
	return (dst);
}
