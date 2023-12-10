/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 17:44:05 by dshatilo          #+#    #+#             */
/*   Updated: 2023/12/09 12:33:20 by dshatilo         ###   ########.fr       */
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

int	max(int a, int b)
{
	return (a * (a >= b) + b * (a < b));
}

int	min(int a, int b)
{
	return (a * (a <= b) + b * (a > b));
}

void	calculate_move(t_moves *m, t_list *a, t_list *b, int b_u)
{
	int	rr;
	int	rrr;
	int	b_d;
	int	a_u;
	int	a_d;

	m->a = get_pos(b, a);
	m->b = b;
	b_d = ft_lstsize(b);
	a_d = ft_lstsize(m->a);
	a_u = ft_lstsize(a) - a_d;
	rr = max(a_u, b_u);
	rrr = max(a_d, b_d);
	m->result = min(rr, rrr);
	m->result = min(m->result, a_d + b_u);
	m->result = min(m->result, a_u + b_d);
	if (m->result == rr)
		m->direction = "rr";
	else if (m->result == rrr)
		m->direction = "rrr";
	else if (m->result == a_d + b_u)
		m->direction = "du";
	else
		m->direction = "ud";
}
