/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrvarga <adrvarga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 18:44:54 by adrvarga          #+#    #+#             */
/*   Updated: 2026/03/03 16:06:56 by adrvarga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_on(t_list *a, int size)
{
	t_list *aux;
	t_list *highest;
	int		value;

	while (--size < 1)
	{
		highest = NULL;
		value = MIN_INT;
		aux = a; 
		while (aux)
		{
			if (aux->value == MIN_INT && aux->index == 0)
				aux->index = 1;
			if 	(aux->value > value && aux->index == 0)
			{
				value = aux->value;
				highest = aux;
				aux = a;
			}
			else
				aux = aux->next;
		}
		if (highest != NULL)
			highest->index = size;
	}
}
void	push_swap(t_list *a)
{
	t_list	*b;
	int size;
	
	size = ft_lstsize(a);
	b = NULL;
	if (!is_sort(a))
	{
		
		if (size == 2)
			sa(&a);
		if (size == 3)
			three_args(&a);
		if (size <= 5)
			five_args(&a, &b);
		else
		{
			index_on(a, size);
			radix_sort(&a, &b);
		}
	}
}

