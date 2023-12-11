/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:09:04 by dshatilo          #+#    #+#             */
/*   Updated: 2023/12/11 22:39:50 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int		*args_arr;

	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		argv = one_arg(argv);
		if (!argv)
			return (0);
		argc = 0;
		while (argv[argc] != NULL)
			argc++;
		args_arr = check_argv(argc, argv);
	}
	else
		args_arr = check_argv(--argc, ++argv);
	if (!args_arr)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	push_swap(args_arr, argc);
	free(args_arr);
	return (0);
}
