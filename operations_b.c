/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 12:13:35 by dshatilo          #+#    #+#             */
/*   Updated: 2023/12/11 09:59:45 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_operations.h"

int	sb(t_list **lst)
{
	swap(lst);
	return (ft_printf("sb\n") == -1);
}

int	pb(t_list **lst_a, t_list **lst_b)
{
	push(lst_b, lst_a);
	return (ft_printf("pb\n") == -1);
}

int	rb(t_list **lst)
{
	rotate(lst);
	return (ft_printf("rb\n") == -1);
}

int	rrb(t_list **lst)
{
	reverse_rotate(lst);
	return (ft_printf("rrb\n") == -1);
}
