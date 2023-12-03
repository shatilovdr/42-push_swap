/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:12:57 by dshatilo          #+#    #+#             */
/*   Updated: 2023/12/03 12:28:11 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_operations.h"

void	swap(t_list **lst)
{
	t_list	*top;
	void	*temp;

	top = *lst;
	if (ft_lstsize(top) < 2)
		return ;
	temp = top->content;
	top->content = top->next->content;
	top->next->content = temp;
}

void	push(t_list **lst1, t_list **lst2)
{
	t_list	*temp;

	if (!lst2)
		return ;
	temp = *lst2;
	*lst2 = temp->next;
	temp->next = *lst1;
	*lst1 = temp;
}

void	rotate(t_list **lst)
{
	t_list	*temp;

	temp = *lst;
	if (ft_lstsize(temp) < 2)
		return ;
	*lst = (*lst)->next;
	temp->next = 0;
	ft_lstadd_back(lst, temp);
}

void	reverse_rotate(t_list **lst)
{
	t_list	*head;
	t_list	*curr;
	size_t	len;

	curr = *lst;
	len = ft_lstsize(curr);
	if (len < 2)
		return ;
	if (len == 2)
	{
		rotate (lst);
		return ;
	}
	while (curr->next->next != 0)
		curr = curr->next;
	head = curr->next;
	curr->next = 0;
	head->next = *lst;
	*lst = head;
}
