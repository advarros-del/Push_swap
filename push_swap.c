/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrvarga <adrvarga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 18:42:45 by adrvarga          #+#    #+#             */
/*   Updated: 2026/02/24 12:51:41 by adrvarga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*push_swap(char **argv, int argc)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	wtf_is_this(argv, argc, &a);
	if (a == NULL)
	{
		write(2, "Error\n", 6);
		return (NULL);
	}
	b = NULL;
	group_on_b(&a, &b);
	sort_b(&a, &b);
	while (b != NULL)
	{
		pushing(&b, &a);
		write(1, "pa\n", 3);
	}
	ft_lstclear(&b);
	return (a);
}

void	group_on_b(t_list **a, t_list **b)
{
	int		index;
	int		counter;
	t_list	*node_a;

	node_a = *a;
	index = 1;
	put_the_index(a);
	counter = bigger_group(*a, &index);
	while (counter != 0)
	{
		while (node_a->index != index)
		{
			rotating(a);
			write(1, "ra\n", 3);
			node_a = *a;
		}
		pushing(a, b);
		write (1, "pb\n", 3);
		counter--;
	}
}

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
			the_move = node_a->index - node_b->index;
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
		{
			rerotating(b);
			write (1, "rrb\n", 4);
		}
		else if (code_mv == 2 || code_mv == 4)
		{
			rotating(b);
			write (1, "rb\n", 3);
		}
		else if (code_mv == 3)
		{
			swapeanding(b);
			write (1, "sb\n", 3);
		}
		the_move--;
	}
}
