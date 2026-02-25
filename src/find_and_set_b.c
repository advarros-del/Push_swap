/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_and_set_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrvarga <adrvarga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 17:50:22 by adrvarga          #+#    #+#             */
/*   Updated: 2026/02/25 19:04:42 by adrvarga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int    find_and_set_b(t_list **b, t_list **node_b, int value, int *code_mv)
{
    while (*node_b != NULL && value < (*node_b)->content)
        *node_b = (*node_b)->next;
    if (*node_b == NULL)
    {
        *node_b = ft_lstlast(*b);
        *code_mv = 4;
        return (1);
	}
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