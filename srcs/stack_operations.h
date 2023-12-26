/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 11:33:06 by dshatilo          #+#    #+#             */
/*   Updated: 2023/12/26 15:45:13 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_OPERATIONS_H
# define STACK_OPERATIONS_H

# include "../lib/libft/libft.h"

void	swap(t_list **lst);
void	push(t_list **lst1, t_list **lst2);
void	rotate(t_list **lst);
void	reverse_rotate(t_list **lst);
void	both(char *mode, t_list **lst1, t_list **lst2);

#endif