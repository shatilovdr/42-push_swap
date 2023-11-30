/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 22:50:23 by dshatilo          #+#    #+#             */
/*   Updated: 2023/11/30 23:21:25 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_arg(char *arg)
{
	int	num;
	int	pos;

	pos = 0;
	if (arg[pos] == '+' || arg[pos] == '-')
		pos++;
	if (!arg[pos])
		return (0);
	while (arg[pos])
		if (!ft_isdigit(arg[pos++]))
			return (0);
	num = ft_atoi(arg);
	pos--;
	if (num == 0)
	{
		while (pos)
			if (arg[pos--] != '0')
				return (0);
		if (arg[pos] != '0' && arg[pos] != '+' && arg[pos] != '-')
			return (0);
	}
	return (1);
}

int	check_argv(int argc, char *argv[])
{
	int	i;
	int	*args;

	if (argc < 2)
		return (0);
	args = (int *)malloc(sizeof(int) * (argc - 1));
	if (!args)
		return (0);
	i = 1;
	while (i < argc)
	{
		if (!check_arg(argv[i]))
		{
			free (args);
			return (0);
		}
	}
	//add check for duplicates;
	return (1);
}
