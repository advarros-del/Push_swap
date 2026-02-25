/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specific_rules.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrvarga <adrvarga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 16:22:19 by adrvarga          #+#    #+#             */
/*   Updated: 2026/02/25 20:16:15 by adrvarga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "push_swap.h"
 
void	is_rotating_b(int *indx_b, t_list **b, int *the_move, int *code_mv)
{
	while ((*indx_b) -1 != 0)
	{
		rb(b);
		(*the_move)++;
		*code_mv = 1;
		(*indx_b)--;
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
		rr(a, b);
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
		rrr(a, b);
		aux--;				
	}
}