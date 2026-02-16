/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrvarga <adrvarga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:01:17 by adrvarga          #+#    #+#             */
/*   Updated: 2026/02/16 19:55:03 by adrvarga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_and_mv_both(t_list **a, t_list **b, t_list *node_a, t_list *node_b)
{
	int	code;

	if (node_b->index <= ft_lstsize(node_b) / 2
		&& node_b->index != 1 && node_b->index != 2
		&& node_a->index <= ft_lstsize(node_b) / 2
		&& node_a->index != 1 && node_a->index != 2)
	{
		is_rotating_all(a, b, node_a, node_b);
		code = 1;
		return (code);
	}
	else if (node_b->index > ft_lstsize(node_b) / 2
		&& node_b->index != 1 && node_b->index != 2
		&& node_a->index > ft_lstsize(node_b) / 2 && node_a->index != 1
		&& node_a->index != 2)
	{
		is_rerotating_all(a, b, node_a, node_b);
		code = 2;
		return (2);
	}
	else
		return (0);
}

void	prepare_b(t_list *node_b, t_list **b, int *the_move, int *code_mv)// no funciona. no cambia al que tiene que ir
{
	int	indx_b;

	indx_b = node_b ->index + 1;
	if (node_b->index == 2)
	{
		swapeanding(b);
		write(1, "sb\n", 3);
	}
	else if (node_b->index <= ft_lstsize(*b) / 2
		&& node_b->index != 1 && node_b->index != 2)
		is_rotating_b(&indx_b, b, the_move, code_mv);
	else if (node_b->index > ft_lstsize(*b) / 2
		&& node_b->index != ft_lstsize(*b))
	{
		while (--indx_b -1 != 0)
		{
			rerotating(b);
			write (1, "rrb\n", 4);
			the_move ++;
			*code_mv = 2;
		}
	}
}

void	prepare_and_send_a(t_list **a, t_list **b, t_list *node_a)// no funciona, no hace el rotate ni nada. revisar
{
	int	indx_a;

	indx_a = node_a->index;
	if (node_a->index <= ft_lstsize(*a) / 2
		&& node_a->index != 1 && node_a->index != 2)
	{
		is_rotating_a(&indx_a, a);
		write(1, "pa\n", 3);
		pushing(a, b);
	}
	else if (node_a->index == 2)
	{
		swapeanding(a);
		write(1, "sa\n", 3);
		write(1, "pa\n", 3);
		pushing(a, b);
	}
	else if (node_a->index > ft_lstsize(*a) / 2
		&& node_a->index != ft_lstsize(*a))
	{
		is_rerotating_a(&indx_a, a);
		write(1, "pa\n", 3);
		pushing(a, b);
	}
}

