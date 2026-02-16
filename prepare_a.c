/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrvarga <adrvarga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 15:33:42 by adrvarga          #+#    #+#             */
/*   Updated: 2026/02/16 19:18:23 by adrvarga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	bigger_group(t_list *a, int *index)
{
	int	c;
	int	temp;
	int	counter;
	int	temp_index;

	counter = 1;
	temp_index = a->index;
	temp = a->content;
	c = 1;
	while (a != NULL)
	{
		if (a->content > temp)
			c++;
		else
		{
			is_bigger(&counter, &c, index, &temp_index);
			c = 1;
			temp_index = a->index;
		}
		temp = a->content;
		a = a->next;
	}
	is_bigger(&counter, &c, index, &temp_index);
	return (counter);
}

void	mv_calculator(t_list **a, t_list **b)
{
	int		mv_a;
	int		mv_b;
	t_list	*node_a;

	mv_b = 0;
	put_the_index(a);
	put_the_index(b);
	node_a = *a;
	while (node_a != NULL)
	{
		if (node_a->index == ft_lstsize(*a))
			mv_a = 2;
		else if (node_a->index > (ft_lstsize(*a) / 2))
			mv_a = (ft_lstsize(*a) - ft_lstsize(*a) / 2) + 2;
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

	node_b = *b;
	while (node_b->next != NULL && node_a->content < node_b->content)
		node_b = node_b->next;
	if (node_b->index == ft_lstsize(*b))
		*mv_b = 1;
	else if (node_b->index - 1 <= ft_lstsize(*b) / 2)
		*mv_b = (node_b->index - 1) * 2;
	else
		*mv_b = 2 * (ft_lstsize(*b) - node_b->index + 1);
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

void	is_bigger(int *counter, int *c, int *index, int *temp_index)
{
	if (*counter < *c)
	{
		*counter = *c;
		*index = *temp_index;
	}
}
