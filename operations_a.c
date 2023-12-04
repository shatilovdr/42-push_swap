/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 12:13:35 by dshatilo          #+#    #+#             */
/*   Updated: 2023/12/04 12:25:33 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_operations.h"

void	sa(t_list **lst)
{
	swap(lst);
	ft_printf("sa\n");
}

void	pa(t_list **lst_a, t_list **lst_b)
{
	push(lst_a, lst_b);
	ft_printf("pa\n");
}

void	ra(t_list **lst)
{
	rotate(lst);
	ft_printf("ra\n");
}

void	rra(t_list **lst)
{
	reverse_rotate(lst);
	ft_printf("rra\n");
}

void	apply_same_time(char *mode, t_list **lst1, t_list **lst2)
{
	void	(*f)(t_list **);

	if (*mode == 's')
	{
		f = swap;
		ft_printf("ss\n");
	}
	else if (*mode == 'r' && mode[1] == 'o')
	{
		f = rotate;
		ft_printf("rr\n");
	}
	else if (*mode == 'r' && mode[1] == 'r')
	{
		f = reverse_rotate;
		ft_printf("rrr\n");
	}
	else
		return ;
	f(lst1);
	f(lst2);
}
