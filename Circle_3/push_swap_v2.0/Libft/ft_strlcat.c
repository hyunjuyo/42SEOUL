/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 12:49:36 by hyunjuyo          #+#    #+#             */
/*   Updated: 2020/12/24 18:06:21 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t j;
	size_t len_dst;
	size_t len_src;

	i = 0;
	while (dst[i])
		i++;
	len_dst = i;
	j = 0;
	while (src[j] && i + 1 < dstsize)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	len_src = 0;
	while (src[len_src])
		len_src++;
	if (dstsize >= len_dst)
		return (len_src + len_dst);
	else
		return (len_src + dstsize);
}
