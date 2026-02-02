/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrvarga <adrvarga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 15:52:55 by adrvarga          #+#    #+#             */
/*   Updated: 2026/01/22 17:16:50 by adrvarga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*******************************************************************
 * atoi transform an ascii number into a regular number in the int *
 ******************************************************************/

int	ft_atoi(const char *nptr)
{
	int	i;
	int	dest;
	int	n;

	dest = 0;
	n = 1;
	i = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if ((nptr[i] == '+' && nptr[i + 1] == '-')
		|| (nptr[i] == '-' && nptr[i + 1] == '+'))
		return (0);
	if (nptr[i] == '+')
		i++;
	if (nptr[i] == '-')
	{
		n = -n;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		dest = (dest * 10) + (nptr[i] - '0');
		i++;
	}
	return (dest * n);
}
/*
int	main(void)
{
	char nptr[65] = "     +25235";

	printf ("%d", ft_atoi(nptr));
	return (0);
}
*/
