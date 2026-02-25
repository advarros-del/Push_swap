/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrvarga <adrvarga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 12:45:53 by adrvarga          #+#    #+#             */
/*   Updated: 2026/02/25 20:01:06 by adrvarga         ###   ########.fr       */
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
void	sb(t_list **x)
{
	t_list	*first;
	t_list	*second;

	first = *x;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*x = second;
	write(1, "sb\n", 3);
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

