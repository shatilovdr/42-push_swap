/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_one_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 15:55:42 by dshatilo          #+#    #+#             */
/*   Updated: 2023/12/26 15:58:25 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	count_words(char *str, char c);

int	*check_one_arg(int *argc, char *argv[])
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