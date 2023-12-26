/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:09:04 by dshatilo          #+#    #+#             */
/*   Updated: 2023/12/26 15:45:30 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/push_swap.h"

int	main(int argc, char *argv[])
{
	int		*args_arr;

	args_arr = check_argc(&argc, argv);
	if (!args_arr)
		return (0);
	push_swap(args_arr, argc);
	free(args_arr);
	return (0);
}
