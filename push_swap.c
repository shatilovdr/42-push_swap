/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 12:15:11 by dshatilo          #+#    #+#             */
/*   Updated: 2023/12/11 21:57:15 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_nothing(void *arg);

void	push_swap(int *args_arr, int argc)
{
	t_list	*lst;
	t_list	*temp;

	lst = create_list(args_arr, argc);
	if (!lst)
	{
		write(2, "Error\n", 6);
		return ;
	}
	temp = 0;
	if (sort_list(&lst, &temp))
	{
		write(2, "Error\n", 6);
		ft_lstclear(&temp, do_nothing);
	}
	ft_lstclear(&lst, do_nothing);
}

void	do_nothing(void *arg)
{
	(void)arg;
}
