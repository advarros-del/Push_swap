/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrvarga <adrvarga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:01:17 by adrvarga          #+#    #+#             */
/*   Updated: 2026/02/16 15:26:43 by adrvarga         ###   ########.fr       */
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

void	prepare_b(t_list *node_b, t_list **b, int *the_move, int *code_mv)
{
	int	indx_b;

	indx_b = node_b ->index + 1;
	if (node_b->index == 2)
	{
		swapeanding(b);
		write(1, "sb", 2);
	}
	else if (node_b->index <= ft_lstsize(*b) / 2
		&& node_b->index != 1 && node_b->index != 2)
	{
		is_rotating(&indx_b, b, the_move, code_mv);
		write (1, "rb", 2);
	}
	else if (node_b->index > ft_lstsize(*b) / 2
		&& node_b->index != ft_lstsize(*b))
	{
		while (--indx_b -1 != 0)
		{
			rerotating(b);
			write (1, "rrb", 3);
			the_move ++;
			*code_mv = 2;
		}
	}
}

void	prepare_and_send_a(t_list **a, t_list **b, t_list *node_a)
{
	int	indx_a;

	indx_a = node_a->index;
	if (node_a->index <= ft_lstsize(*a) / 2
		&& node_a->index != 1 && node_a->index != 2)
	{
		is_rotating(&indx_a, a, 0, 0);
		write(1, "pa\n", 1);
		pushing(a, b);
	}
	else if (node_a->index == 2)
	{
		swapeanding(a);
		write(1, "sa", 2);
		write(1, "pa\n", 1);
		pushing(a, b);
	}
	else if (node_a->index > ft_lstsize(*a) / 2
		&& node_a->index != ft_lstsize(*a))
	{
		while (indx_a -1 != 0)
		{
			rerotating(a);
			indx_a--;
			write (1, "rra", 3);
		}
		write(1, "pa\n", 1);
		pushing(a, b);
	}
}

void	is_rotating_all(t_list **a, t_list **b, t_list *node_a, t_list *node_b)
{
	int	aux;

	aux = node_b->index - node_a->index;
	if (aux < 0)
		aux = aux * -1;
	while (aux != 0)
	{
		rotating(a);
		rotating(b);
		write(1, "rr", 2);
		aux--;
	}
}

void	is_rerotating_all(t_list **a, t_list **b, t_list *node_a, t_list *node_b)
{
	int	aux;

	aux = node_b->index - node_a->index;
	if (aux < 0)
		aux = aux * -1;
	while (aux != 0)
	{
		rerotating(a);
		rerotating(b);
		write(1, "rrr", 2);
		aux--;				
	}
}

void	is_rotating(int *indx_x, t_list **x, int *the_move, int *code_mv)
{
	while (--indx_x -1 != 0)
	{
		rotating(x);
		the_move ++;
		*code_mv = 1;
	}
}
