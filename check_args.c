/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrvarga <adrvarga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 18:07:46 by adrvarga          #+#    #+#             */
/*   Updated: 2026/02/16 19:13:13 by adrvarga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	**wtf_is_this(char **argv, int argc, t_list **a)
{
	int	i;
	int	j;
	int	s;
	int	n;

	i = 1;
	while (i < argc)
	{
		s = 0;
		j = 0;
		while (argv[i][j] != '\0' && is_dg_or_sp(argv[i][j], &s) == 1)
			j++;
		if (argv[i][j] != '\0')
			return (NULL);
		else if (s == 1)
			gimmi_nbr(argv[i], a);
		else
		{
			n = atoi(argv[i]);
			send_to_list(n, a);
		}
		i++;
	}
	return (a);
}

t_list	**send_to_list(int n, t_list **a)
{
	t_list	*new_node;

	new_node = ft_lstnew(n);
		ft_lstadd_back(a, new_node);
	return (a);
}

t_list	**gimmi_nbr(char *str, t_list **a)
{
	char	**matrix;
	int		i;
	int		n;

	matrix = ft_split(str, ' ');
	if (matrix == NULL)
		return (NULL);
	i = 0;
	while (matrix[i])
	{
		n = ft_atoi(matrix[i]);
		if (n == 0)//Cambiar a otro error porque 0 es un numero posible. 
			return (NULL);
		send_to_list(n, a);
		i++;
	}
	ft_free_all(matrix, i);
	return (a);
}

void	ft_free_all(char **str, int i)
{
	while (i >= 0)
	{
		free(str[i]);
		i--;
	}
	free(str);
}
