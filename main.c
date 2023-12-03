/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:09:04 by dshatilo          #+#    #+#             */
/*   Updated: 2023/12/03 11:31:19 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(void *content)
{
	ft_printf("%d ", *(int *)content);
}

int	main(void)
{
	int		*arr;
	t_list	*lst1;
	t_list	*lst2;
	int		i;

	arr = (int *)malloc(sizeof(int) * 10);
	i = 0;
	while (i < 10)
	{
		arr[i] = i;
		i++;
	}
	lst1 = create_list(arr, 5);
	lst2 = create_list(arr + 5, 5);
	ft_lstiter(lst1, print_list);
	ft_printf("\n");
	ft_lstiter(lst2, print_list);
	ft_printf("\n\n");
	push(&lst1, &lst2);
	rotate(&lst1);
	ft_lstiter(lst1, print_list);
	ft_printf("\n");
	ft_lstiter(lst2, print_list);
	return (0);
}

//Check why there is no segfault in revers_rotate 
	//when lst contains 2 elements only. 


// int	main(int argc, char *argv[])
// {
// 	t_list	*lst;
// 	int		*args; //FREE YOUR ARGS!!!!

// 	if (argc < 2)
// 	{
// 		write(1, "\n", 1);
// 		return (0);
// 	}
// 	args = check_argv(--argc, ++argv);
// 	if (!args)
// 	{
// 		write(2, "Error\n", 6);
// 		return (0);
// 	}
// 	lst = create_list(args, argc);
// 	if (!lst)
// 	{
// 		write(2, "Error\n", 6);
// 		return (0);
// 	}
// 	return (0);
// }