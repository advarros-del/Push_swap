/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrvarga <adrvarga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 18:42:45 by adrvarga          #+#    #+#             */
/*   Updated: 2026/02/26 20:04:49 by adrvarga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*push_swap(t_list *a)
{
	t_list	*b;

	if (!is_sort(a))
	{
		if (ft_lstsize(a) <= 3)
			three_args(&a);
		else
		{
			b = NULL;
			pb(&a, &b);
			sort_b(&a, &b);
			while (b != NULL)
				pa(&b, &a);
			ft_lstclear(&b);
		}
	}
	return (a);
}

// void	group_on_b(t_list **a, t_list **b)
// {
// 	int		index;
// 	int		counter;
// 	t_list	*node_a;

// 	node_a = *a;
// 	index = 1;
// 	put_the_index(a);
// 	counter = bigger_group(*a, &index);
// 	while (counter != 0)
// 	{
// 		while (node_a->index != index)
// 		{
// 			ra(a);
// 			node_a = *a;
// 		}
// 		pb(a, b);
// 		counter--;
// 	}
// }

void	sort_b(t_list **a, t_list **b)
{
	int		minimun;
	t_list	*node_a;
	t_list	*node_b;
	int		the_move;
	int		code_mv;

	minimun = 0;
	the_move = 0;
	while (*a != NULL)
	{
		node_b = *b;
		node_a = *a;
		mv_calculator(a, b);
		min_mv(a, &minimun);
		while (minimun != node_a->mv)
			node_a = node_a->next;
		the_move = find_and_set_b(b, &node_b, node_a->content, &code_mv);
		if (code_mv != 4)
			code_mv = check_and_mv_both(a, b, node_a, node_b);
		if (code_mv != 0 && code_mv < 4)
			the_move = check_mv(node_a->index, node_b->index);
		prepare_b(node_b, b, &the_move, &code_mv);
		prepare_and_send_a(a, b, node_a);
		resort_b(b, the_move, code_mv);
	}
}

void	min_mv(t_list **a, int *minimun)
{
	t_list	*node_a;

	node_a = *a;
	*minimun = node_a->mv;
	while (node_a != NULL)
	{
		if (*minimun > node_a->mv)
			*minimun = node_a->mv;
		node_a = node_a->next;
	}
}

void	resort_b(t_list **b, int the_move, int code_mv)
{
	while (the_move != 0)
	{
		if (code_mv == 1)
			rrb(b);
		else if (code_mv == 2 || code_mv == 4)
			rb(b);
		else if (code_mv == 3)
			sb(b);
		the_move--;
	}
}
