/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrvarga <adrvarga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 12:45:53 by adrvarga          #+#    #+#             */
/*   Updated: 2026/03/03 16:29:58 by adrvarga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **x)
{
	t_list	*first;
	t_list	*second;

	first = *x;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*x = second;
	write(1, "sa\n", 3);
}

void	pa(t_list **bye, t_list **hey)
{
	t_list	*temp;

	temp = *bye;
	*bye = (*bye)->next;
	temp->next = *hey;
	*hey = temp;
	write(1, "pa\n", 3);
}

void	pb(t_list **bye, t_list **hey)
{
	t_list	*temp;

	temp = *bye;
	*bye = (*bye)->next;
	temp->next = *hey;
	*hey = temp;
	write(1, "pb\n", 3);
}


void	ra(t_list **x)
{
	t_list	*first;
	t_list	*last;

	first = *x;
	last = *x;
	while (last->next != NULL)
		last = last->next;
	*x = first->next;
	first->next = NULL;
	last->next = first;
	write(1, "ra\n", 3);
}

void	rra(t_list **x)
{
	t_list	*last;
	t_list	*prev;

	prev = NULL;
	last = *x;
	while (last->next != NULL)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *x;
	*x = last;
	write(1, "rra\n", 4);
}
