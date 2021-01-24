/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 12:13:40 by hyunjuyo          #+#    #+#             */
/*   Updated: 2020/12/02 10:46:44 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	*ft_print_memory(void *addr, unsigned int size)
{
	int		i;
	long	addr_long;

	if (size == 0)
		return (0);
	i = 1;
	addr_long = (long)addr;
	write(1, " ", 1);
	return (addr);
}
