/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wthanata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 21:15:48 by wthanata          #+#    #+#             */
/*   Updated: 2022/03/11 00:42:43 by wthanata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ptr;
	t_list	*add;
	void	*data;

	if (lst == NULL)
		return (NULL);
	data = (*f)(lst->content);
	ptr = ft_lstnew(data);
	if (ptr == NULL)
		ft_lstclear(&lst, del);
	lst = lst->next;
	while (lst)
	{
		data = (*f)(lst->content);
		add = ft_lstnew(data);
		if (add == NULL)
			ft_lstclear(&ptr, del);
		ft_lstadd_back(&ptr, add);
		lst = lst->next;
	}
	return (ptr);
}
