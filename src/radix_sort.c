/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrvarga <adrvarga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 12:24:24 by adrvarga          #+#    #+#             */
/*   Updated: 2026/03/03 16:32:52 by adrvarga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void radix_sort(t_list **a, t_list **b)
{
	int	max_bytes;
	int current_byte;
	int size;
	int	i;

	max_bytes = 0;
	size = ft_lstsize(*a);
	while (size >> max_bytes != 0)
		max_bytes++;
	current_byte = 0;
	while (current_byte < max_bytes)
	{
		i = 0;
		while (i < size)
		{
			if ((((*a)->index >> current_byte) & 1) == 1)
				ra(a);
			else
				pb(a, b);
			i++;
		}
		while (*b != NULL)
			pa(b, a);
		current_byte++;
	}
}
