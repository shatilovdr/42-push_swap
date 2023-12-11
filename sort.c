/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 12:52:49 by dshatilo          #+#    #+#             */
/*   Updated: 2023/12/11 17:50:50 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	**small_sort(t_list **lst);

int		empty_b_recursively(t_list **a, t_list **b);

int		push_benfitial(t_steps s, t_list **a, t_list **b);

void	final_rotate(t_list **lst);

void	sort_list(t_list **a, t_list **b)
{
	if (is_sorted(a))
		return ;
	while (ft_lstsize(*a) > 3)
		pb(a, b);
	a = small_sort(a);
	empty_b_recursively(a, b);
	final_rotate(a);
}

t_list	**small_sort(t_list **lst)
{
	if (*(int *)(*lst)->content > *(int *)(*lst)->next->content
		&& *(int *)(*lst)->content > *(int *)ft_lstlast((*lst))->content)
		ra(lst);
	if (*(int *)(*lst)->content > *(int *)(*lst)->next->content)
		sa(lst);
	if (*(int *)(*lst)->next->content > *(int *)ft_lstlast((*lst))->content)
		rra(lst);
	if (*(int *)(*lst)->content > *(int *)(*lst)->next->content)
		sa(lst);
	return (lst);
}

int	empty_b_recursively(t_list **a, t_list **b)
{
	int		i;
	int		len_b;
	t_list	*curr;
	t_steps	*steps;

	len_b = ft_lstsize(*b);
	if (len_b == 0)
		return (0);
	steps = (t_steps *)malloc(sizeof(t_steps) * len_b);
	if (!steps)
		return (1);
	curr = *b;
	i = 0;
	while (curr)
	{
		calculate_steps(steps + i, *a, curr, i);
		curr = curr->next;
		i++;
	}
	i = find_benefitial(steps, len_b);
	push_benfitial(steps[i], a, b);
	free (steps);
	return (empty_b_recursively(a, b));
}

int	push_benfitial(t_steps s, t_list **a, t_list **b)
{
	int	flag;

	flag = 0;
	if (!(ft_strncmp(s.dir, "rr", 3) && ft_strncmp(s.dir, "rrr", 3)))
		while (*a != s.a && *b != s.b)
			flag = apply_same_time(s.dir, a, b);
	if (flag)
		return (1);
	while (*a != s.a)
	{
		if (!(ft_strncmp(s.dir, "rr", 3) && ft_strncmp(s.dir, "ud", 2)))
			flag = ra(a);
		else
			flag = rra(a);
		if (flag)
			return (1);
	}
	while (*b != s.b)
	{
		if (!(ft_strncmp(s.dir, "rr", 3) && ft_strncmp(s.dir, "du", 2)))
			flag = rb(b);
		else
			flag = rrb(b);
	}
	return (pa(a, b));
}

void	final_rotate(t_list **lst)
{
	t_list	*temp;
	t_list	*min;
	int		len;
	int		pos;

	pos = 0;
	min = get_node_min_content(*lst);
	temp = *lst;
	while (temp != min)
	{
		temp = temp->next;
		pos++;
	}
	len = ft_lstsize(*lst);
	if (pos < len - pos)
		while (*lst != min)
			ra(lst);
	else
		while (*lst != min)
			rra(lst);
}
