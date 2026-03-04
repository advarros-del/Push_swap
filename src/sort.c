/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrvarga <adrvarga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 11:46:30 by adrvarga          #+#    #+#             */
/*   Updated: 2026/03/04 18:39:51 by adrvarga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sort(t_list *a)
{
    int n_prev;

    n_prev = a->value;
    a = a->next;

    while (a)
    {
        if (n_prev > a->value)
            return (0);
		n_prev = a->value;
		a = a->next;
    }
	return (1);
}
void three_args(t_list **a)
{
    t_list *aux;

    aux = *a;
    if (find_min(*a) == aux->value)
	{
		min_on_top(a);
		return;
	} 
    aux = aux->next;
    if (find_min(*a) == aux->value)
    {
        sa(a);
        if (!(is_sort(*a)))
			min_on_top(a);
		return;
	}
    rra(a);
    	if (!(is_sort(*a)))
    		min_on_top(a);	
}
void	five_args(t_list **a, t_list **b)
{
    int		aux;
	t_list	*min;

	min = *a;
	while (ft_lstsize(*a) != 3)
	{
		aux = find_min(*a);
		while (aux != (*a)->value)
			ra(a);
		pb(a, b);
	}
	if (!(is_sort(*a)))
		three_args(a);
	while (*b != NULL)
		pa(b, a);
}

int	find_min(t_list *a)
{
	int value;
	
	value = a->value;
	a = a->next;
	while (a)
	{
		if(a->value < value)
			value = a->value;
		a = a->next;
	}
	return (value);
}

void	min_on_top(t_list **a)
{
	rra(a);
	sa(a);
}