/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 22:50:23 by dshatilo          #+#    #+#             */
/*   Updated: 2023/12/12 18:22:51 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	count_words(char *str, char c);

int		*check_argv(int argc, char *argv[]);

int		check_arg(char *arg, int *num);

int		check_duplicates(int len, int *args);

int		*one_arg(int *argc, char *argv[]);

int	*check_argc(int *argc, char *argv[])
{
	int	*args_arr;

	if (*argc < 2)
		return (0);
	if (*argc == 2 && count_words(argv[1], ' ') > 1)
		args_arr = one_arg(argc, argv);
	else
		args_arr = check_argv(--(*argc), ++argv);
	if (!args_arr)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	return (args_arr);
}

int	*one_arg(int *argc, char *argv[])
{
	int	*args_arr;
	int	len;

	len = count_words(argv[1], ' ');
	argv = ft_split(argv[1], ' ');
	if (!argv)
		return (NULL);
	*argc = len;
	args_arr = check_argv(*argc, argv);
	while (len >= 0)
		free(argv[len--]);
	free(argv);
	return (args_arr);
}

size_t	count_words(char *str, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (*(str + i) != 0)
	{
		if (!(*(str + i) == c))
			if (i == 0 || *(str + i - 1) == c)
				count++;
		i++;
	}
	return (count);
}

int	*check_argv(int argc, char *argv[])
{
	int	i;
	int	*args;

	if (argc <= 0)
		return (NULL);
	args = (int *)malloc(sizeof(int) * (argc));
	if (!args)
		return (NULL);
	i = 0;
	while (i < argc)
	{
		if (check_arg(argv[i], &args[i]))
		{
			free (args);
			return (NULL);
		}
		i++;
	}
	if (check_duplicates(argc, args))
	{
		free (args);
		return (NULL);
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
		return (1);
	while (arg[pos])
		if (!ft_isdigit(arg[pos++]))
			return (1);
	*num = ft_atoi(arg);
	pos--;
	if (*num == 0)
	{
		while (pos)
			if (arg[pos--] != '0')
				return (1);
		if (arg[pos] != '0' && arg[pos] != '+' && arg[pos] != '-')
			return (1);
	}
	return (0);
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
				return (1);
			i--;
		}
		i = j;
		j++;
	}
	return (0);
}
