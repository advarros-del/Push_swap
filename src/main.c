/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrvarga <adrvarga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 15:54:01 by adrvarga          #+#    #+#             */
/*   Updated: 2026/03/04 13:17:45 by adrvarga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list *a;
	
	a = NULL;
	if (argc < 2)
		return (0);
	wtf_is_this(argv, argc, &a);
	if (a == NULL || dupply(a) == 1)
	{
		write(2, "Error\n", 6);
		return (1);
	}
		push_swap(a);
		ft_lstclear(&a);
	return (0);
}
