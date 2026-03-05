/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrvarga <adrvarga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 11:46:30 by adrvarga          #+#    #+#             */
/*   Updated: 2026/03/05 12:53:16 by adrvarga         ###   ########.fr       */
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
    int aux1;
	int aux2;
	int aux3;
	
	aux1 = (*a)->value;
	aux2 = (*a)->next->value;
    aux3 = (*a)->next->next->value;
    if (aux1 < aux2 && aux1 < aux3)
	{
		rra(a);
		sa(a);
	} 
    else if (aux1 > aux2 && aux1 > aux3)
    {
		ra(a);
		if (!(is_sort(*a)))
			sa(a);
	}
	else if (aux2 > aux1 && aux2 > aux3 && aux1 > aux3)
		rra(a);
	else if (aux1 > aux2 && aux1 < aux3 && aux3 > aux2)
		sa(a);    	
}
void	five_args(t_list **a, t_list **b)
{
    int		aux;
	int		i;
	t_list	*min;

	i = 1;
	while (ft_lstsize(*a) != 3)
	{
		min = *a;
		aux = find_min(*a);
		while (min->value != aux)
		{
			min = min->next;
			i++;
		}
		while ((*a)->value != aux)
			if (i <= (ft_lstsize(*a) / 2))
				ra(a);
			else
				rra(a);
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