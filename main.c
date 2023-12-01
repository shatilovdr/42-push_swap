/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:09:04 by dshatilo          #+#    #+#             */
/*   Updated: 2023/12/01 13:16:11 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	main(int argc, char *argv[])
{
	int	*args; //FREE YOUR ARGS!!!!
	args = check_argv(argc, argv);
	if (!args)
	{
		ft_printf("Error\n");
		return (0);
	}
		for (int i = 0; i < argc - 1; i++)
			printf("%d ", args[i]);
		printf("\nSUCCESS!");

	return (0);
}

