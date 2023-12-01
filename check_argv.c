/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 22:50:23 by dshatilo          #+#    #+#             */
/*   Updated: 2023/12/01 13:46:34 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_arg(char *arg, int *num);

int	check_duplicates(int len, int *args);

int	*check_argv(int argc, char *argv[])
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
		if (!check_arg(argv[i], &args[i - 1]))
		{
			free (args);
			return (0);
		}
		i++;
	}
	if (!check_duplicates(argc - 1, args))
	{
		free (args);
		return (0);
	}
	return (args);
}

int	check_arg(char *arg, int *num)
{
	int	pos;

	pos = 0;
	if (arg[pos] == '+' || arg[pos] == '-')
		pos++;
	if (!arg[pos])
		return (0);
	while (arg[pos])
		if (!ft_isdigit(arg[pos++]))
			return (0);
	*num = ft_atoi(arg);
	pos--;
	if (*num == 0)
	{
		while (pos)
			if (arg[pos--] != '0')
				return (0);
		if (arg[pos] != '0' && arg[pos] != '+' && arg[pos] != '-')
			return (0);
	}
	return (1);
}

int	check_duplicates(int len, int *args)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (j < len)
	{
		while (i >= 0)
		{
			if (args[j] == args[i])
				return (0);
			i--;
		}
		i = j;
		j++;
	}
	return (1);
}
