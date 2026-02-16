/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specific_rules.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrvarga <adrvarga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 16:22:19 by adrvarga          #+#    #+#             */
/*   Updated: 2026/02/16 17:22:57 by adrvarga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "push_swap.h"
 
void	is_rotating_a(int *indx_a, t_list **a)
{
	while (--(*indx_a) -1 != 0)
	{
		rotating(a);
		write (1, "ra\n", 3);
	}
}

void	is_rotating_b(int *indx_b, t_list **b, int *the_move, int *code_mv)
{
	while (--(*indx_b) -1 != 0)
	{
		rotating(b);
		write (1, "rb\n", 3);
		(*the_move)++;
		*code_mv = 1;
	}
}
void	is_rerotating_a(int *indx_a, t_list **a)
{
	while (--(*indx_a) -1 != 0)
	{
		rerotating(a);
		write (1, "rra\n", 4);
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
		write(1, "rr\n", 3);
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
		write(1, "rrr\n", 4);
		aux--;				
	}
}