/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dg_or_sp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrvarga <adrvarga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:27:19 by adrvarga          #+#    #+#             */
/*   Updated: 2026/03/04 15:56:44 by adrvarga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_dg_or_sp(char *arg)
{
	int	i;
	
	i = 0;
	while(arg[i] != '\0')
	{
		if (arg[i] == '-' && ft_isdigit(arg[i +1]) == 1
			&& ( i == 0 || ft_isdigit(arg[i - 1]) == 0))
			i++;
		else if (arg[i] == '+' && ft_isdigit(arg[i +1]) == 1
			&& ( i == 0 ||ft_isdigit(arg[i - 1]) == 0))
			i++;
		else if (ft_isdigit(arg[i]) == 1)
			i++;
		else if (arg[i] == 32)
			i++;
		else
			return (0);
	}
	return (1);
}
int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}
