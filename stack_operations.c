/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:12:57 by dshatilo          #+#    #+#             */
/*   Updated: 2023/12/02 17:11:28 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **lst)
{
	t_list	*top;
	void	*temp;

	top = *lst;
	temp = top->content;
	top->content = top->next->content;
	top->next->content = temp;
	ft_printf("\n");
}

void	sswap(t_list **lst1, t_list **lst2)
{
	swap(lst1);
	swap(lst2);
}

void	push(t_list **lst1, t_list **lst2)
{
	t_list	*temp;

	if (!lst2)
		return ;
	temp = *lst2;
	lst2 = &(temp->next);
	temp->next = *lst1;
	lst1 = &temp;
}
