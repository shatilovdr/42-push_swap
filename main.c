/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:09:04 by dshatilo          #+#    #+#             */
/*   Updated: 2023/11/29 16:48:43 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	check_argv(int argc, char *argv[])
{
	int		i;
	char	*arg;

	i = 1;
	while (i < argc)
	{
		arg = argv[i];
		while (*arg)
		{
			if (!ft_isdigit(*arg))
				return (0);
			arg++;
		}
		i++;
	}
	return (1);
}

#include <stdio.h>

int	main(void)
{
	int				a;
	unsigned int	b;

	b = -1;
	a = b / 2;
	ft_printf("%d", a);
	return (0);
}


