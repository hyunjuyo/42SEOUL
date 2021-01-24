/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 20:05:55 by hyunjuyo          #+#    #+#             */
/*   Updated: 2020/12/02 14:33:09 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int idx_d;
	unsigned int idx_s;

	idx_d = 0;
	while (dest[idx_d] != '\0')
		idx_d++;
	idx_s = 0;
	while (src[idx_s] != '\0' && idx_s < nb)
	{
		dest[idx_d] = src[idx_s];
		idx_d++;
		idx_s++;
	}
	dest[idx_d] = '\0';
	return (dest);
}
