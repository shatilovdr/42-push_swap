/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:09:04 by dshatilo          #+#    #+#             */
/*   Updated: 2023/12/04 17:41:56 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(void *content);

void	fill_array(int *arr, int size);

int		is_sorted(t_list **plst);

void	sort_lst(t_list **lst1, t_list **lst2);

int	main(void)
{
	int		*arr;
	t_list	*lst;
	t_list	*temp;
	int		size;

	size = 5;
	arr = (int *)malloc(sizeof(int) * size);
	fill_array(arr, size);
	arr[0] = 4;
	arr[1] = 2;
	arr[2] = 0;
	arr[3] = 3;
	arr[4] = 1;
	lst = create_list(arr, size);
	temp = 0;
	ft_lstiter(lst, print_list);
	sort_lst(&lst, &temp);
	ft_printf("\n");

	return (0);
}

void	sort_lst(t_list **lst1, t_list **lst2)
{
	t_list	*a;
	t_list	*b;

	a = *lst1;
	b = *lst2;
	if (!b && is_sorted(&a))
		return ;
	if (ft_lstsize(a) > 1)
	{
		pb(&a, &b);
		if (ft_lstsize(b) > 1 && *(int *)b->content < *(int *)b->next->content)
			rb(&b);
	}
	if (ft_lstsize(a) == 1)
		pb(&a, &b);
	ft_lstiter(b, print_list);
	sort_lst(&a, &b);
}

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
	ft_printf("%d ", *(int *)content);
}
