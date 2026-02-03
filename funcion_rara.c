/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcion_rara.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrvarga <adrvarga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 15:33:42 by adrvarga          #+#    #+#             */
/*   Updated: 2026/02/03 16:52:40 by adrvarga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	bigger_group(t_list *a, int *index)
{
	int	c;
	int	temp;
	int	counter;

	counter = 1;
	temp = *(a->content);
	c = 1;
	while (a->next != NULL)
	{
		if (*(a->content) > temp)
			c++;
		else
		{
			if (counter < c)
				counter = c;
			c = 1;
			*index = a->index;
		}
		temp = *(a->content);
		a = a->next;
	}
	return (c);
}

void	mv_calculator(t_list **a, t_list **b)
{
	int		mv_a;
	int		mv_b;
	t_list	*temp;
	t_list	*node_a;

	temp = *b;
	node_a = *a;
	put_the_index(a);
	put_the_index(b);
	while (node_a->next != NULL)
	{
		if (node_a->index == ft_lstsize(*a))
			mv_a = 2;
		else if (node_a->index > (ft_lstsize(*a) / 2))
			mv_a = ((ft_lstsize(*a) / 2) - ft_lstsize(*a)) + 2;
		else
			mv_a = node_a->index;
		calculate_b(node_a, b, &mv_b);
		node_a->mv = mv_a + mv_b;
		node_a = node_a->next;
	}
}

void	calculate_b(t_list *node_a, t_list **b, int *mv_b)
{
	while ((*b)->next != NULL)
	{
		if (node_a->content < (*b)->content)
			*b = (*b)->next;
	}
	if ((*b)->index == ft_lstsize(*b))
		(*b)->mv = 1;
	else if ((*b)->index - 1 <= ft_lstsize(*b) / 2)
		(*b)->mv = ((*b)->index - 1) * 2;
	else
		*mv_b = 2 * (ft_lstsize(*b) - (*b)->index + 1);
}

void	put_the_index(t_list **x)
{
	int	n;

	n = 1;
	while ((*x)->next != NULL)
	{
		(*x)->index = n;
		n++;
		*x = (*x)->next;
	}
}
