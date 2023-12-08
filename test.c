/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 19:24:48 by dshatilo          #+#    #+#             */
/*   Updated: 2023/12/08 20:54:46 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(void *content);

void	calculate_move(t_moves *m, t_list *a, t_list *b, int pos_b);


// typedef struct s_moves
// {
// 	int		a_u;
// 	int		a_d;
// 	int		b_u;
// 	int		b_d;
// 	int		result;
// 	short	direction;
// }	t_moves;

void	print_move(t_moves *moves)
{
	t_moves	m;

	m = *moves;
	
	ft_printf("a_u: %d\n", m.a_u);
	ft_printf("a_d: %d\n", m.a_d);
	ft_printf("b_u: %d\n", m.b_u);
	ft_printf("b_d: %d\n", m.b_d);
	ft_printf("result: %d\n", m.result);
	ft_printf("direction: %d\n", m.direction);
	ft_printf("---------------------\n");
}

void	super_sort(t_list *a, t_list *b)
{
	int		len_b;
	int		i;
	t_moves	*moves;//FREE YOUR MOVES

	i = 0;
	len_b = ft_lstsize(b);
	moves = (t_moves *)malloc(sizeof(t_moves) * len_b);
		//if (!moves)
	while (b)
	{
		calculate_move(moves + i, a, b, i);
		b = b->next;
		i++;
	}
}


int	main(void)
{
	int		*arr;
	t_list	*lst_1;
	t_list	*lst_2;
	int		size;

	size = 10;
	arr = (int *)malloc(sizeof(int) * size);
	arr[0] = 10;
	arr[1] = 20;
	arr[2] = 30;
	arr[3] = 40;
	arr[4] = 50;
	arr[5] = 60;
	arr[6] = 5;
	arr[7] = 28;
	arr[8] = 44;
	arr[9] = 100;
	lst_1 = create_list(arr, 5);
	lst_2 = create_list(arr + 5, 5);
	ft_lstiter(lst_1, print_list);
	ft_printf("\n");
	ft_lstiter(lst_2, print_list);
	super_sort(lst_1, lst_2);
	return (0);
}

int	max(int a, int b)
{
	return (a * (a >= b) + b * (a < b));
}

int	min(int a, int b)
{
	return (a * (a <= b) + b * (a > b));
}

void	calculate_move(t_moves *m, t_list *a, t_list *b, int pos_b)
{
	int		rr;
	int		rrr;

	m->b_u = pos_b;
	m->b_d = ft_lstsize(b);
	m->a_u = ft_lstsize(a);
	a = get_pos(b, a);
	m->a_d = ft_lstsize(a);
	m->a_u -= m->a_d;
	rr = max(m->a_u, m->b_u);
	rrr = max(m->a_d, m->b_d);
	m->result = min(rr, rrr);
	m->result = min(m->result, m->a_d + m->b_u);
	m->result = min(m->result, m->a_u + m->b_d);
	if (m->result == rr)
		m->direction = 11;
	else if (m->result == rrr)
		m->direction = 0;
	else if (m->result == m->a_d + m->b_u)
		m->direction = 01;
	else
		m->direction = 10;
	ft_printf("---------------------\n");
	ft_printf("ac: %d\n", *(int *)a->content);
	ft_printf("bc: %d\n", *(int *)b->content);
	print_move(m);
}


void	print_list(void *content)
{
	ft_printf("%d\n", *(int *)content);
}
