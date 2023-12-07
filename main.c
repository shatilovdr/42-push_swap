/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:09:04 by dshatilo          #+#    #+#             */
/*   Updated: 2023/12/05 15:48:14 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(void *content);

void	fill_array(int *arr, int size);

int		is_sorted(t_list **plst);

int		is_sorted_b(t_list **plst);

t_list	*sort_lst(t_list *a, t_list *b);

// int	main(void)
// {
// 	int		*arr;
// 	t_list	*lst;
// 	t_list	*temp;
// 	int		size;

// 	size = 4;
// 	arr = (int *)malloc(sizeof(int) * size);
// 	fill_array(arr, size);
// 	arr[0] = 2;
// 	arr[1] = 3;
// 	arr[2] = 1;
// 	arr[3] = 4;
// 	// arr[4] = 8;
// 	lst = create_list(arr, size);
// 	temp = 0;
// 	ft_lstiter(lst, print_list);
// 	ft_printf("\n");
// 	lst = sort_lst(lst, temp);
// 	ft_lstiter(lst, print_list);


// 	return (0);
// }

void	aaa(void *test)
{
	*(int *)test += 0;
}

int	main(int argc, char *argv[])
{
	t_list	*lst;
	t_list	*temp;
	int		*args; //FREE YOUR ARGS!!!!

	if (argc < 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	args = check_argv(--argc, ++argv);
	if (!args)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	lst = create_list(args, argc);
	if (!lst)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	temp = 0;
	lst = sort_lst(lst, temp);
	ft_lstclear(&lst, aaa);
	free(args);
	return (0);
}


t_list	*check_improve(t_list *a)
{
	int	actions;
	int	first;
	int	second;
	int	last;

	if (ft_lstsize(a) < 2)
		return (a);
	first = *(int *)a->content;
	second = *(int *)a->next->content;
	last = *(int *)ft_lstlast(a)->content;
	actions = 0;
	if (first < second && second > last)
	{
		rra(&a);
		actions++;
	}
	if (first > second)
	{
		sa(&a);
		actions++;
	}
	if (actions)
		return (check_improve(a));
	return (a);
}

t_list	*sort_lst(t_list *a, t_list *b)
{
	int		j;

	j = 0;
	a = check_improve(a);
	if (!b && is_sorted(&a))
		return (a);
	if (!b || *(int *)a->content > *(int *)b->content)
		pb(&a, &b);
	else if (b && *(int *)a->content < *(int *)b->content)
	{
		pb(&a, &b);
		rb(&b);
		while (*(int *)b->content > *(int *)ft_lstlast(b)->content)
		{
			pa(&a, &b);
			j++;
		}
		rrb(&b);
		if (is_sorted(&a) && is_sorted_b(&b))
		{
			while (ft_lstsize(b))
				pa(&a, &b);
			return (a);
		}
		while (j--)
			pb(&a, &b);
	}
	if (!a)
		while (ft_lstsize(b))
			pa(&a, &b);
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

int	is_sorted_b(t_list **plst)
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
		if (ncontent > content)
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
		temp = 0 + rand() % 10;
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
