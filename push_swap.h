/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:32:32 by dshatilo          #+#    #+#             */
/*   Updated: 2023/12/12 16:23:51 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>

typedef struct s_steps
{
	t_list	*a;
	t_list	*b;
	int		result;
	char	*dir;
}	t_steps;

int		*check_argc(int *argc, char *argv[]);
void	push_swap(int *args_arr, int argc);
t_list	*create_list(int *arr, int length);
int		sort_list(t_list **a, t_list **b);
int		is_sorted(t_list **plst);
void	calculate_steps(t_steps *s, t_list *a, t_list *b, int b_u);
t_list	*find_pos_to_push(t_list *lst_1, t_list *lst_2);
int		find_benefitial(t_steps	*steps, int len);
int		free_steps(t_steps *steps);
t_list	*get_node_min_content(t_list *lst);
void	do_nothing(void *arg);

int		sa(t_list **lst);
int		pa(t_list **lst_a, t_list **lst_b);
int		ra(t_list **lst);
int		rra(t_list **lst);
int		sb(t_list **lst);
int		pb(t_list **lst_a, t_list **lst_b);
int		rb(t_list **lst);
int		rrb(t_list **lst);
int		apply_same_time(char *mode, t_list **lst1, t_list **lst2);

#endif