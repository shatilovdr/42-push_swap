/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:09:04 by dshatilo          #+#    #+#             */
/*   Updated: 2023/12/10 18:26:43 by dshatilo         ###   ########.fr       */
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

int	push_swap(t_moves m, t_list **a, t_list **b)
{
	if (!(ft_strncmp(m.dir, "rr", 3) && ft_strncmp(m.dir, "rrr", 3)))
		while (*a != m.a && *b != m.b)
			apply_same_time(m.direction, a, b);
	while (*a != m.a)
	{
		if (!(ft_strncmp(m.dir, "rr", 3) && ft_strncmp(m.dir, "ud", 2)))
			ra(a);
		else
			rra(a);
	}
	while (*b != m.b)
	{
		if (!(ft_strncmp(m.dir, "rr", 3) && ft_strncmp(m.dir, "du", 2)))
			rb(b);
		else
			rrb(b);
	}
	pa(a, b);
}

int	optimal(t_moves	*moves, int len)
{
	int	i;
	int	min;
	int	min_index;

	i = 0;
	min_index = 0;
	min = moves[0].result;
	while (i < len)
	{
		if (moves[i].result < min)
		{
			min = moves[i].result;
			min_index = i;
		}
		i++;
	}
	return (min_index);
}

void	super_sort(t_list **pa, t_list **pb)
{
	int		i;
	int		len_b;
	t_list	*a;
	t_list	*b;
	t_moves	*moves;//FREE YOUR MOVES

	i = 0;
	a = *pa;
	b = *pb;
	len_b = ft_lstsize(b);
	moves = (t_moves *)ft_calloc(len_b, sizeof(t_moves));
		//if (!moves)
				
	while (b)
	{
		calculate_move(moves + i, a, b, i);
		b = b->next;
		i++;
	}
	i = optimal(moves, len_b);
	push_swap(moves[i], pa, pb);
	free (moves);
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
