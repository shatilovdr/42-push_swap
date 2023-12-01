/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:09:04 by dshatilo          #+#    #+#             */
/*   Updated: 2023/12/01 15:25:47 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	test(void *input)
{
	int	*a;

	a = (int *)input;
	ft_printf("%d ", *a);
}

int	main(int argc, char *argv[])
{
	int		*args; //FREE YOUR ARGS!!!!
	int		i;
	t_list	*lst;
	

	args = check_argv(--argc, ++argv);
	if (!args)
	{
		ft_printf("Error\n");
		return (0);
	}
	i = 0;
	lst = 0;
	while (i < argc)
	{
		ft_lstadd_back(&lst, ft_lstnew(args + i));
		i++;
	}
	ft_lstiter(lst, test);

	// for (int j = 0; j < argc; j++)
	// 	printf("%d ", args[i]);
	// printf("\nSUCCESS!");

	return (0);
}

