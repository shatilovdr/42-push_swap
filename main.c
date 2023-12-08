/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:09:04 by dshatilo          #+#    #+#             */
/*   Updated: 2023/12/08 19:24:24 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(void *content);

void	fill_array(int *arr, int size);

int		is_sorted(t_list **plst);

t_list	*sort_lst(t_list *a, t_list *b);

int	main(void)
{
	int		*arr;
	t_list	*lst;
	t_list	*temp;
	int		size;

	size = 5;
	arr = (int *)malloc(sizeof(int) * size);
	fill_array(arr, size);
	arr[0] = 923;
	arr[1] = 900;
	arr[2] = 1020;
	arr[3] = 1050;
	arr[4] = 45;
	lst = create_list(arr, size);
	temp = 0;
	pb(&lst, &temp);
	ft_lstiter(temp, print_list);
	ft_printf("\n\n\n");
	ft_lstiter(lst, print_list);
	ft_printf("\n\n\n");
	ft_lstiter(get_pos(temp, lst), print_list);
	return (0);
}

int	max(int a, int b)
{
	return (a * (a >= b) + b * (a < b));
}

int	min(int a, int b)
{
	return (a * (a <= b) + b * (a > b));
}


void	calculate_move(t_moves *m, t_list *a, t_list *b, int pos_b)
{
	int		rr;
	int		rrr;

	m->b_u = pos_b;
	m->b_d = ft_lstsize(b);
	m->a_u = ft_lstsize(a);
	a = get_pos(b, a);
	m->a_d = ft_lstsize(a);
	m->a_u -= m->a_d;
	rr = max(m->a_u, m->b_u);
	rrr = max(m->a_d, m->b_d);
	m->result = min(rr, rrr);
	m->result = min(m->result, m->a_d + m->b_u);
	m->result = min(m->result, m->a_u + m->b_d);
	if (m->result == rr)
		m->direction = 11;
	else if (m->result == rrr)
		m->direction = 0;
	else if (m->result == m->a_d + m->b_u)
		m->direction = 01;
	else
		m->direction = 10;
}

void	super_sort(t_list *a, t_list *b)
{
	int		len_b;
	int		i;
	t_moves	*moves;//FREE YOUR MOVES

	i = 0;
	len_b = ft_lstsize(b);
	moves = (t_moves *)malloc(sizeof(t_moves) * len_b);
		//if (!moves)
	while (i < len_b)
	{
		calculate_move(moves + i, a, b, i);
		i++;
	}
	free(moves);
}


t_list	*sort_lst(t_list *a, t_list *b)
{
	if (!b && is_sorted(&a))
		return (a);
	if (!b)
	{
		while (ft_lstsize(a) > 3)
			pb(&a, &b);
		a = small_sort(&a);
	}
	// if (b)
	// 	super_sort(a, b);
	return (sort_lst(a, b));
}

int	is_sorted(t_list **plst)
{
	t_list	*lst;
	int		content;
	int		ncontent;

	lst = *plst;
	if (!lst)
		return (0);
	content = *(int *)(lst->content);
	while (lst->next)
	{
		ncontent = *(int *)(lst->next->content);
		if (ncontent < content)
			return (0);
		content = ncontent;
		lst = lst->next;
	}
	return (1);
}

void	fill_array(int *arr, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	srand(time(NULL));
	while (i < size)
	{
		temp = -50 + rand() % 100;
		j = 0;
		while (j < i)
		{
			if (arr[j] == temp)
				break ;
			j++;
		}
		if (arr[j] == temp)
			continue ;
		arr[i] = temp;
		i++;
	}
}

void	print_list(void *content)
{
	ft_printf("%d\n", *(int *)content);
}
