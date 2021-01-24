/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 20:17:47 by hyunjuyo          #+#    #+#             */
/*   Updated: 2020/12/02 14:34:31 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		find_len_check(char *to_find)
{
	int len;

	len = 0;
	while (to_find[len] != '\0')
		len++;
	return (len);
}

char	*ft_strstr(char *str, char *to_find)
{
	int idx_s;
	int count;
	int find_len;

	find_len = find_len_check(to_find);
	if (find_len == 0)
		return (str);
	idx_s = 0;
	while (str[idx_s] != '\0')
	{
		count = 0;
		if (str[idx_s] == to_find[count])
		{
			while (str[idx_s + count] == to_find[count])
			{
				if (str[idx_s + count] == '\0')
					break ;
				count++;
			}
			if (count == find_len)
				return (str + idx_s);
		}
		idx_s++;
	}
	return (0);
}
