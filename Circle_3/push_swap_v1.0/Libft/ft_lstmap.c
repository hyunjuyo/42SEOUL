/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 19:53:01 by hyunjuyo          #+#    #+#             */
/*   Updated: 2020/12/28 20:11:22 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ptr;
	t_list	*ptr_n;

	if (!lst)
		return (0);
	ptr = ft_lstnew(f(lst->content));
	ptr_n = ptr;
	while (lst->next)
	{
		lst = lst->next;
		if (!(ptr_n->next = ft_lstnew(f(lst->content))))
			del(ptr);
		ptr_n = ptr_n->next;
	}
	ptr_n->next = 0;
	return (ptr);
}
