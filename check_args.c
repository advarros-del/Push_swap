/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrvarga <adrvarga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 18:07:46 by adrvarga          #+#    #+#             */
/*   Updated: 2026/02/24 12:55:13 by adrvarga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	**wtf_is_this(char **argv, int argc, t_list **a)
{
	int			i;
	int			j;
	int			s;
	long int	n;

	i = 0;
	while (++i < argc)
	{
		s = 0;
		j = 0;
		while (argv[i][j] != '\0' && is_dg_or_sp(argv[i][j], &s) == 1)
			j++;
		if (is_empty(argv[i]) == 0)
			return (NULL);
		if (argv[i][j] != '\0')
			return (NULL);
		else if (s == 1)
			gimmi_nbr(argv[i], a);
		else
		{
			n = atol(argv[i]);
			if (send_to_list(n, a) == NULL)
				return (NULL);
		}
	}
	return (a);
}

t_list	**send_to_list(long int n, t_list **a)
{
	t_list	*new_node;
	
	if (n > MAX_INT || n < MIN_INT)
		return (ft_lstclear(a), NULL);
	new_node = ft_lstnew(n);
		ft_lstadd_back(a, new_node);
	return (a);
}

t_list	**gimmi_nbr(char *str, t_list **a)
{
	char			**matrix;
	int				i;
	long int		n;

	matrix = ft_split(str, ' ');
	if (matrix == NULL)
		return (NULL);
	i = 0;
	while (matrix[i])
	{
		n = ft_atol(matrix[i]);
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

int	is_empty(char *str)
{
	int	n;
	int	i;

	i = 0; 
	n = 1;
	if (str[0] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] != 32)
			n = 1;
		i++;
	}
	return (n);
}
