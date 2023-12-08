/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 17:44:05 by dshatilo          #+#    #+#             */
/*   Updated: 2023/12/08 17:47:40 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*get_max(t_list *lst)
{
	t_list	*max;

	max = lst;
	while (lst)
	{
		if (*(int *)lst->content > *(int *)max->content)
			max = lst;
		lst = lst->next;
	}
	return (max);
}

t_list	*get_pos(t_list *lst_1, t_list *lst_2)
{
	t_list	*min_abv_c;
	t_list	*max;

	max = get_max(lst_2);
	if (*(int *)max->content < *(int *)lst_1->content)
	{
		if (max->next)
			return (max->next);
		else
			return (lst_2);
	}
	min_abv_c = max;
	while (lst_2)
	{
		if (*(int *)lst_2->content > *(int *)lst_1->content
			&& *(int *)lst_2->content < *(int *)min_abv_c->content)
			min_abv_c = lst_2;
		lst_2 = lst_2->next;
	}
	return (min_abv_c);
}

t_list	*small_sort(t_list **plst)
{
	t_list	*lst;

	lst = *plst;
	if (*(int *)lst->content > *(int *)lst->next->content
		&& *(int *)lst->content > *(int *)ft_lstlast(lst)->content)
		ra(&lst);
	if (*(int *)lst->content > *(int *)lst->next->content)
		sa(&lst);
	if (*(int *)lst->next->content > *(int *)ft_lstlast(lst)->content)
		rra(&lst);
	if (*(int *)lst->content > *(int *)lst->next->content)
		sa(&lst);
	return (lst);
}