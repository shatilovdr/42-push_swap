/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:09:04 by dshatilo          #+#    #+#             */
/*   Updated: 2023/12/02 18:49:40 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*lst;
	int		i;
	int		*args; //FREE YOUR ARGS!!!!

	if (argc < 2)
	{
		write(2, "\n", 1);
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
	return (0);
}



// int	main(void)
// {
// 	int		*arr;
// 	t_list	*lst1;
// 	t_list	*lst2;
// 	t_list	*temp;
// 	int		i;

// 	arr = (int *)malloc(sizeof(int) * 10);
// 	i = 1;
// 	while (i <= 10)
// 		arr[i - 1] = i++;
// 	i = 0;
// 	while (i < 5)
// 	{
// 		temp = ft_lstnew(arr + i++);
// 		if (!temp)
// 		{
// 			ft_lstclear(lst1, free);
// 			return
// 		}
// 		ft_lstadd_back(&lst1, temp);
// 	}


// 	return (0);
// }

