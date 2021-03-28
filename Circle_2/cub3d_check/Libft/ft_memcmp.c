/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 13:00:49 by hyunjuyo          #+#    #+#             */
/*   Updated: 2020/12/24 18:30:45 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	int		diff;

	diff = 0;
	if (n == 0)
		return (diff);
	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
		{
			diff = ((unsigned char *)s1)[i] - ((unsigned char *)s2)[i];
			return (diff);
		}
		i++;
	}
	i--;
	diff = ((unsigned char *)s1)[i] - ((unsigned char *)s2)[i];
	return (diff);
}
