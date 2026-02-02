/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrvarga <adrvarga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 12:45:53 by adrvarga          #+#    #+#             */
/*   Updated: 2026/02/02 19:08:49 by adrvarga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swapeanding(t_list **x)
{
	t_list	*first;
	t_list	*second;

	first = *x;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*x = second;
}

void	pushing(t_list **bye, t_list **hey)
{
	t_list	*temp;

	temp = *bye;
	*bye = (*bye)->next;
	temp->next = *hey;
	*hey = temp;
}

void	rotating(t_list **x)
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
}

void	rerotating(t_list **x)
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
}
