/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 17:01:25 by hyunjuyo          #+#    #+#             */
/*   Updated: 2020/12/24 18:04:22 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*ptr;

	ptr = 0;
	i = -1;
	while (s[++i])
	{
		if (s[i] == c)
			ptr = (char *)s + i;
	}
	if (s[i] == c)
		ptr = (char *)s + i;
	return (ptr);
}
