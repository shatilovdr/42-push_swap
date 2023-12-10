/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 19:24:48 by dshatilo          #+#    #+#             */
/*   Updated: 2023/12/09 13:52:13 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(void)
{
	t_moves	*moves;

	moves = (t_moves *)ft_calloc(2, sizeof(t_moves));

	moves[0].direction = "sdf";
	moves[0].result = 3;
	ft_printf("%s\n", moves[0].direction);
	ft_printf("%s\n", moves[1].direction);
	ft_printf("%d\n", moves[0].result);
	ft_printf("%d\n", moves[1].result);
	return (0);
}
