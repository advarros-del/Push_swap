/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrvarga <adrvarga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 20:01:16 by adrvarga          #+#    #+#             */
/*   Updated: 2026/02/25 20:01:41 by adrvarga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_list **x)
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
	write(1, "rb\n", 3);
}
void	rr(t_list **x, t_list **y)
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
	first = *y;
	last = *y;
	while (last->next != NULL)
		last = last->next;
	*y = first->next;
	first->next = NULL;
	last->next = first;
	write(1, "rr\n", 3);
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
void	rrb(t_list **x)
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
	write(1, "rrb\n", 4);
}
void	rrr(t_list **x, t_list **y)
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
	prev = NULL;
	last = *y;
	while (last->next != NULL)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *y;
	*y = last;
	write(1, "rrr\n", 4);
}