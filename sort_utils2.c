/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 17:44:05 by dshatilo          #+#    #+#             */
/*   Updated: 2023/12/11 17:49:01 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*get_node_max_content(t_list *lst);

t_list	*find_pos_to_push(t_list *lst_1, t_list *lst_2)
{
	t_list	*min_abv_c;
	t_list	*max;

	max = get_node_max_content(lst_2);
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

t_list	*get_node_max_content(t_list *lst)
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

t_list	*get_node_min_content(t_list *lst)
{
	t_list	*min;

	min = lst;
	while (lst)
	{
		if (*(int *)lst->content < *(int *)min->content)
			min = lst;
		lst = lst->next;
	}
	return (min);
}
