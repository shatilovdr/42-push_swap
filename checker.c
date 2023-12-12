/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:59:41 by dshatilo          #+#    #+#             */
/*   Updated: 2023/12/12 17:44:05 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack_operations.h"

int	checker(int *args_arr, int argc);
int	apply_func(char *mode, t_list **lst1, t_list **lst2);

int	main(int argc, char *argv[])
{
	int		*args_arr;
	int		res;

	args_arr = check_argc(&argc, argv);
	if (!args_arr)
		return (0);
	res = checker(args_arr, argc);
	if (res == -1)
		write(2, "Error\n", 6);
	else if (res == 1)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	free(args_arr);
	return (0);
}

int	checker(int *args_arr, int argc)
{
	t_list	*lst;
	t_list	*temp;
	int		flag;
	char	*curr;

	lst = create_list(args_arr, argc);
	if (!lst)
		return (-1);
	temp = 0;
	curr = get_next_line(0);
	flag = 0;
	while (curr && !flag)
	{
		flag = apply_func(curr, &lst, &temp);
		curr = get_next_line(0);
	}
	if (flag)
	{
		ft_lstclear(&lst, do_nothing);
		ft_lstclear(&temp, do_nothing);
		return (-1);
	}
	return (is_sorted(&lst) || temp != NULL);
}

int	apply_func(char *mode, t_list **lst1, t_list **lst2)
{
	if (!ft_strncmp(mode, "ra", 2))
		rotate(lst1);
	else if (!ft_strncmp(mode, "rb", 2))
		rotate(lst2);
	else if (!ft_strncmp(mode, "rra", 3))
		reverse_rotate(lst1);
	else if (!ft_strncmp(mode, "rrb", 3))
		reverse_rotate(lst2);
	else if (!ft_strncmp(mode, "sa", 2))
		swap(lst1);
	else if (!ft_strncmp(mode, "sb", 2))
		swap(lst2);
	else if (!ft_strncmp(mode, "pa", 2))
		push(lst1, lst2);
	else if (!ft_strncmp(mode, "pb", 2))
		push(lst2, lst1);
	else if (!ft_strncmp(mode, "ss", 2) || !ft_strncmp(mode, "rrr", 3)
		|| !ft_strncmp(mode, "rr", 2))
		both(mode, lst1, lst2);
	else
		return (1);
	return (0);
}
