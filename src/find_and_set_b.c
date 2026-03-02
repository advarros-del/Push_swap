/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_and_set_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrvarga <adrvarga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 17:50:22 by adrvarga          #+#    #+#             */
/*   Updated: 2026/03/02 16:57:22 by adrvarga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int    find_and_set_b(t_list **b, t_list **node_b, int value, int *code_mv)
{
    while (*node_b != NULL && value < (*node_b)->content)
        *node_b = (*node_b)->next;
    if (*node_b == NULL || (*node_b == ft_lstlast(*b) && (*node_b)->index > 2))
    {
        *node_b = ft_lstlast(*b);
        *code_mv = 4;
        return (1);
	}
	else if ((*node_b)->index == 2)
	{
		*code_mv = 3;
		return (1);
	}
	code_mv = 0;
    return (0);
}
int	is_sort(t_list *a)
{
    int n_prev;

    n_prev = a->content;
    a = a->next;

    while (a)
    {
        if (n_prev > a->content)
            return (0);
		n_prev = a->content;
		a = a->next;
    }
	return (1);
}
int check_mv(int a, int b)
{
    int c;

    c = a - b;
    if (c < 0)
        c *= -1;
    return (c);
}
void three_args(t_list **a)
{
    int x;
    int y;
    int z;

    x = (*a)->content;
    (*a) = (*a)->next;
    y = (*a)->content;
    (*a) = (*a)->next;
    z = (*a)->content;
    (*a) = (*a)->next;
    if (x > y  && x > z)
    {
        ra(a);
        if (!is_sort(*a))
            sa(a);
    }
    if (x < y && x < z)
    {
        rra(a);
        sa(a);
    }
    if (x > z)
        rra(a);
    else
        sa(a);
}
// void five_args(t_list **a)
// {
//     t_list *min:
    
    


    
//     find_min(a)
    
// }


// the move = find_and_set_b()
// if (in_the_middle > 0) 
// {
	
// }