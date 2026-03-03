/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrvarga <adrvarga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 15:54:01 by adrvarga          #+#    #+#             */
/*   Updated: 2026/03/03 15:58:00 by adrvarga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list *a;
	int	count;
	char **split_args;
	
	a = NULL;
	count = 0;
	if (argc == 2)
	{
		split_args = ft_split(argv[1], ' ');
		
		wtf_is_this(split_args -1, count + 1, &a);
		ft_free_all(split_args, count - 1);
	}
	else
		wtf_is_this(argv, argc, &a);
	if (a == NULL || dupply(a) == 1)
	{
		write(2, "Error\n", 6);
		return (1);
	}
		push_swap(a);
	return (0);
}
