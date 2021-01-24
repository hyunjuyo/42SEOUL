/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 12:13:25 by hyunjuyo          #+#    #+#             */
/*   Updated: 2020/12/06 17:40:51 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>

# define BUFSIZE 2000

void	ft_ntow(char *num[]);
void	ft_ntow_newdict(char *num[], char *dict[]);
int		ft_dict_check(char *dict_buf);
void	ft_convert_num(char *dict_buf, char *num[]);
char	*ft_strstr(char *str, char *to_find);
void	ft_write_word(char *start);

#endif
