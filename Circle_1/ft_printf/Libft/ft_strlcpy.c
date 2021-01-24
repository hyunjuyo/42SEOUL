/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 12:06:03 by hyunjuyo          #+#    #+#             */
/*   Updated: 2020/12/29 21:55:58 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	int i;

	if (!dst && !src)
		return (0);
	i = -1;
	while (src[++i] && (size_t)(i + 1) < dstsize)
		dst[i] = src[i];
	if (dstsize != 0)
		dst[i] = '\0';
	i = 0;
	while (src[i])
		i++;
	return (i);
}
