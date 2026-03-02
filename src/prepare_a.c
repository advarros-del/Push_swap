/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrvarga <adrvarga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 15:33:42 by adrvarga          #+#    #+#             */
/*   Updated: 2026/03/02 16:04:18 by adrvarga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mv_calculator(t_list **a, t_list **b)
{
	int		mv_a;
	int		mv_b;
	t_list	*node_a;
	int		size;
	
	size = ft_lstsize(*a);
	mv_b = 0;
	put_the_index(a);
	put_the_index(b);
	node_a = *a;
	while (node_a != NULL)
	{
		if (node_a->index == size)
			mv_a = 2;
		else if (node_a->index > (size / 2))
			mv_a = (size - size / 2) + 2;
		else
			mv_a = node_a->index;
		calculate_b(node_a, b, &mv_b);
		node_a->mv = mv_a + mv_b;
		node_a = node_a->next;
	}
}

void	calculate_b(t_list *node_a, t_list **b, int *mv_b)
{
	t_list	*node_b;
	int		size;
	
	size = ft_lstsize(*b);
	node_b = *b;
	while (node_b->next != NULL && node_a->content < node_b->content)
		node_b = node_b->next;
	if (node_b->index == 1)
		return;
	else if (node_b->index == size)
		*mv_b = 1;
	else if (node_b->index - 1 <= size / 2)
		*mv_b = (node_b->index - 1) * 2;
	else
		*mv_b = 2 * (size - node_b->index + 1);
}

void	put_the_index(t_list **x)
{
	t_list	*node;
	int		n;

	node = *x;
	n = 1;
	while (node->next != NULL)
	{
		node->index = n;
		n++;
		node = node->next;
	}
	node->index = n;
}
void	min_num(t_list **a, int *minimun)
{
	t_list	*node_a;

	node_a = *a;
	*minimun = node_a->content;
	while (node_a != NULL)
	{
		if (*minimun > node_a->content)
			*minimun = node_a->content;
		node_a = node_a->next;
	}
}