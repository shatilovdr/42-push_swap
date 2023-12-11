/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 12:52:49 by dshatilo          #+#    #+#             */
/*   Updated: 2023/12/11 22:41:15 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		small_sort(t_list **lst);

int		empty_b_recursively(t_list **a, t_list **b);

int		push_benfitial(t_steps s, t_list **a, t_list **b);

int		final_rotate(t_list **lst);

int	sort_list(t_list **a, t_list **b)
{
	if (!is_sorted(a))
		return (0);
	while (ft_lstsize(*a) > 3)
		if (pb(a, b))
			return (1);
	if (small_sort(a))
		return (1);
	if (empty_b_recursively(a, b))
		return (1);
	if (final_rotate(a))
		return (1);
	return (0);
}

int	small_sort(t_list **lst)
{
	int	flag;

	flag = 0;
	if (*(int *)(*lst)->content > *(int *)(*lst)->next->content
		&& *(int *)(*lst)->content > *(int *)ft_lstlast((*lst))->content)
		flag = ra(lst);
	if (*(int *)(*lst)->content > *(int *)(*lst)->next->content
		&& !flag)
		flag = sa(lst);
	if (*(int *)(*lst)->next->content > *(int *)ft_lstlast((*lst))->content
		&& !flag)
		flag = rra(lst);
	if (*(int *)(*lst)->content > *(int *)(*lst)->next->content
		&& !flag)
		flag = sa(lst);
	if (flag)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	return (0);
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
	if (push_benfitial(steps[i], a, b))
		return (ft_free(steps));
	free (steps);
	return (empty_b_recursively(a, b));
}

int	push_benfitial(t_steps s, t_list **a, t_list **b)
{
	int	flag;

	flag = 0;
	if (!(ft_strncmp(s.dir, "rr", 3) && ft_strncmp(s.dir, "rrr", 3)))
		while (*a != s.a && *b != s.b && !flag)
			flag = apply_same_time(s.dir, a, b);
	while (*a != s.a && !flag)
	{
		if (!(ft_strncmp(s.dir, "rr", 3) && ft_strncmp(s.dir, "ud", 2)))
			flag = ra(a);
		else
			flag = rra(a);
	}
	while (*b != s.b && !flag)
	{
		if (!(ft_strncmp(s.dir, "rr", 3) && ft_strncmp(s.dir, "du", 2)))
			flag = rb(b);
		else
			flag = rrb(b);
	}
	if (flag)
		return (1);
	return (pa(a, b));
}

int	final_rotate(t_list **lst)
{
	t_list	*temp;
	t_list	*min;
	int		len;
	int		pos;
	int		flag;

	flag = 0;
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
		while (*lst != min && !flag)
			flag = ra(lst);
	else
		while (*lst != min && !flag)
			flag = rra(lst);
	if (flag)
		return (1);
	return (0);
}
