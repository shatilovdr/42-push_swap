/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:51:11 by dshatilo          #+#    #+#             */
/*   Updated: 2023/12/11 21:14:14 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max(int a, int b);

int	min(int a, int b);

int	is_sorted(t_list **plst)
{
	t_list	*lst;
	int		content;
	int		ncontent;

	lst = *plst;
	content = *(int *)(lst->content);
	while (lst->next)
	{
		ncontent = *(int *)(lst->next->content);
		if (ncontent < content)
			return (1);
		content = ncontent;
		lst = lst->next;
	}
	return (0);
}

void	calculate_steps(t_steps *s, t_list *a, t_list *b, int b_u)
{
	int	rr;
	int	rrr;
	int	b_d;
	int	a_u;
	int	a_d;

	s->a = find_pos_to_push(b, a);
	s->b = b;
	b_d = ft_lstsize(b);
	a_d = ft_lstsize(s->a);
	a_u = ft_lstsize(a) - a_d;
	rr = max(a_u, b_u);
	rrr = max(a_d, b_d);
	s->result = min(rr, rrr);
	s->result = min(s->result, a_d + b_u);
	s->result = min(s->result, a_u + b_d);
	if (s->result == rr)
		s->dir = "rr";
	else if (s->result == rrr)
		s->dir = "rrr";
	else if (s->result == a_d + b_u)
		s->dir = "du";
	else
		s->dir = "ud";
}

int	find_benefitial(t_steps	*steps, int len)
{
	int	i;
	int	min;
	int	min_index;

	i = 0;
	min_index = 0;
	min = steps[0].result;
	while (i < len)
	{
		if (steps[i].result < min)
		{
			min = steps[i].result;
			min_index = i;
		}
		i++;
	}
	return (min_index);
}

int	max(int a, int b)
{
	return (a * (a >= b) + b * (a < b));
}

int	min(int a, int b)
{
	return (a * (a <= b) + b * (a > b));
}
