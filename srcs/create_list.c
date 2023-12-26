/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 17:55:59 by dshatilo          #+#    #+#             */
/*   Updated: 2023/12/11 21:04:50 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*create_list(int *arr, int length)
{
	t_list	*lst;
	t_list	*temp;
	int		i;

	i = 0;
	lst = 0;
	while (i < length)
	{
		temp = ft_lstnew(arr + i++);
		if (!temp)
		{
			ft_lstclear(&lst, do_nothing);
			return (NULL);
		}
		ft_lstadd_back(&lst, temp);
	}
	return (lst);
}
