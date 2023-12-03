/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 12:13:35 by dshatilo          #+#    #+#             */
/*   Updated: 2023/12/03 12:36:16 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_operations.h"

void	sb(t_list **lst)
{
	swap(lst);
	ft_pritnf("sb\n");
}

void	pb(t_list **lst_a, t_list **lst_b)
{
	push(lst_b, lst_a);
	ft_pritnf("pb\n");
}

void	rb(t_list **lst)
{
	rotate(lst);
	ft_pritnf("rb\n");
}

void	rrb(t_list **lst)
{
	reverse_rotate(lst);
	ft_pritnf("rrb\n");
}
