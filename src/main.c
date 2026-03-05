/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrvarga <adrvarga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 15:54:01 by adrvarga          #+#    #+#             */
/*   Updated: 2026/03/05 15:33:18 by adrvarga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	
	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	a = wtf_is_this(argv, argc, &a);
	if (a == NULL || dupply(a) == 1)
	{
		write(2, "Error\n", 6);
		ft_lstclear(&a);
		a = NULL;
		return (1);
	}
	push_swap(&a, &b);
	ft_lstclear(&a);
	ft_lstclear(&b);
	a = NULL;
	b = NULL;
	return (0);
}
