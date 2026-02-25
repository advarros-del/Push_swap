/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrvarga <adrvarga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:01:17 by adrvarga          #+#    #+#             */
/*   Updated: 2026/02/25 20:23:12 by adrvarga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_and_mv_both(t_list **a, t_list **b, t_list *node_a, t_list *node_b)
{
	int	code;
	int size;

	size = ft_lstsize(node_b);
	if (node_b->index <= size / 2 && node_b->index != 1
		&& node_b->index != 2 && node_a->index <= size / 2
		&& node_a->index != 1 && node_a->index != 2)
	{
		is_rotating_all(a, b, node_a, node_b);
		code = 1;
		return (code);
	}
	else if (node_b->index > size / 2 && node_b->index != 1
		&& node_b->index != 2 && node_a->index > size / 2
		&& node_a->index != 1 && node_a->index != 2)
	{
		is_rerotating_all(a, b, node_a, node_b);
		code = 2;
		return (2);
	}
	else
		return (0);
}

void	prepare_b(t_list *node_b, t_list **b, int *the_move, int *code_mv)
{
	int	i;
	int size;
	
	size = ft_lstsize(*b);
	i = node_b->index;
	if (i == 2)
	{
		sb(b);
		*code_mv = 3;
		(*the_move)++;
	}	
	else if (i <= size / 2 && i > 2)
		is_rotating_b(&i, b, the_move, code_mv);
	else if (i > size / 2 && i != size)
	{
		while (--i > 0)
		{
			rrb(b);
			(*the_move)++;
			*code_mv = 2;
		}
	}
}

void	prepare_and_send_a(t_list **a, t_list **b, t_list *node_a)
{
	int	i;

	i = node_a->index;
	if (i <= ft_lstsize(*a) / 2 && i != 1 && i != 2)
		while (--i != 0)
			ra(a);
	else if (i == 2)
		sa(a);
	else if (i > ft_lstsize(*a) / 2 && i != 1)
	{
		if (i == ft_lstsize(*a))
			i = 1;
		while (--i != 0)
				rra(a);
	}
	pa(a, b);
}
