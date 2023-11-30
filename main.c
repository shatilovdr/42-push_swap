/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:09:04 by dshatilo          #+#    #+#             */
/*   Updated: 2023/11/30 18:53:34 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


// int	check_argv(char *argv)
// {
// 	long	num;
// 	char	*arg;
// 	int		pos;

// 	arg = argv;
// 	pos = 0;
// 	if (!arg[pos])
// 		return (0);
// 	while (arg[pos])
// 	{
// 		if (arg[pos] == '+' || arg[pos] == '-')
// 			pos++;
// 		if (!ft_isdigit(arg[pos]))
// 			return (0);
// 	}
// 	num = ft_atoi(arg);
// 	return (1);
// }


int	main(void)
{
	char	test[1000];

	for (int i = 0; i < 1000; i++)
	{
		test[i] = i;
	}

	return (0);
}


// int	check_argv(char *argv)
// {
// 	long	num;
// 	char	*arg;
// 	int		pos;

// 	arg = argv;
// 	pos = ft_strlen(arg) - 1;
// 	num = ft_atoi(arg);
// 	if ((arg[0] == '-' || arg[0] == '+') && !ft_isdigit(arg[1]))
// 		return (0);
// 	if (num < 0 && arg[0] != '-')
// 		return (0);
// 	num *= -1 * (num < 0) + (num >= 0);
// 	while (num != 0)
// 	{
// 		if (num % 10 != arg[pos] - '0')
// 			return (0);
// 		num /= 10;
// 	}
// 	if (!num)
// 	{
// 		while (pos != 0)
// 			if (arg[pos--])
// 				return (0);
// 		if (arg[0] != '-' && arg[0] != '+' && arg[0] != '0')
// 			return (0);
// 	}
// 	return (1);
// }