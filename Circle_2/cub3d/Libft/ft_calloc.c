/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 17:02:39 by hyunjuyo          #+#    #+#             */
/*   Updated: 2020/12/24 18:32:03 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	i;

	ptr = malloc(size * count);
	if (!ptr)
		return (0);
	i = 0;
	while (i < size * count)
	{
		((unsigned char *)ptr)[i] = 0;
		i++;
	}
	return (ptr);
}
