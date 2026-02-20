/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrvarga <adrvarga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:01:17 by adrvarga          #+#    #+#             */
/*   Updated: 2026/02/20 18:04:15 by adrvarga         ###   ########.fr       */
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
	i = node_b->index - 1;
	if (i == 2)
		*code_mv = 3; 
	else if (i <= size / 2 && i > 2)
		is_rotating_b(&i, b, the_move, code_mv);
	else if (i > size / 2 && i != size)
	{
		while (--i > 0)
		{
			rerotating(b);
			write (1, "rrb\n", 4);
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
		is_rotating_a(&i, a);
	else if (i == 2)
	{
		swapeanding(a);
		write(1, "sa\n", 3);
	}
	else if (i > ft_lstsize(*a) / 2 && i != 1)
		is_rerotating_a(&i, a);
	write(1, "pb\n", 3);
	pushing(a, b);
}

