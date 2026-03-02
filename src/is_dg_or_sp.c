/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dg_or_sp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrvarga <adrvarga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:27:19 by adrvarga          #+#    #+#             */
/*   Updated: 2026/02/26 14:35:56 by adrvarga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_dg_or_sp(char *arg, int *s)
{
	int	i;
	
	i = 0;
	while(arg[i] != '\0')
	{
		if (arg[i] == '-' && arg[i + 1] != '\0' && arg[i + 1] != 32)
			i++;
		else if (arg[i] == '+' && arg[i + 1] != '\0' && arg[i + 1] != 32)
			i++;
		else if (arg[i] >= 48 && arg[i] <= 57)
			i++;
		else if (arg[i] == 32)
		{
			*s = 1;
			i++;
		}
		else
			return (0);
	}
	return (1);
}
