/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plus_and_minus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrvarga <adrvarga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 15:09:28 by adrvarga          #+#    #+#             */
/*   Updated: 2026/01/28 16:03:16 by adrvarga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	plus_index(t_list *x)
{
	while (x->next != NULL)
	{
		x->index++;
		x = x->next;
	}
}

void	minus_index(t_list *x)
{
	while (x->next != NULL)
	{
		x->index--;
		x = x->next;
	}
}
