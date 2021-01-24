/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 17:01:25 by hyunjuyo          #+#    #+#             */
/*   Updated: 2020/12/24 18:07:01 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*ptr;

	i = -1;
	while (s[++i])
	{
		if (s[i] == c)
		{
			ptr = (char *)s + i;
			return (ptr);
		}
	}
	if (s[i] == c)
	{
		ptr = (char *)s + i;
		return (ptr);
	}
	return (0);
}
