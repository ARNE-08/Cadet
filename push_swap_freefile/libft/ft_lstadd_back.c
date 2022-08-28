/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wthanata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 20:36:16 by wthanata          #+#    #+#             */
/*   Updated: 2022/03/12 22:41:16 by wthanata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ptr;

	if (new == NULL)
		return ;
	ptr = *lst;
	if (ptr)
	{
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = new;
	}
	else
		*lst = new;
}
