/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrvarga <adrvarga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 18:07:46 by adrvarga          #+#    #+#             */
/*   Updated: 2026/03/05 14:42:30 by adrvarga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*wtf_is_this(char **argv, int argc, t_list **a)
{
	int			i;
	long int	n;
	char		**matrix;
	int 		j;
	
	i = 1;
	while (i < argc)
	{
		if (is_dg_or_sp(argv[i]) == 0  || is_empty(argv[i]) == 0)
			return (ft_lstclear(a) ,NULL);
		matrix = ft_split(argv[i], ' ');
		if (matrix == NULL)
			return (ft_lstclear(a) ,NULL);
		j = 0;
		while (matrix[j])
		{
			n = ft_atol(matrix[j]);
			if (send_to_list(n, a) == NULL)
				return (ft_free_all(matrix),ft_lstclear(a), NULL);
			j++;
		}
		ft_free_all(matrix);
		i++;
		}
	return (*a);
}

t_list	*send_to_list(long int n, t_list **a)
{
	t_list	*new_node;
	
	if (n > MAX_INT || n < MIN_INT)
		return (ft_lstclear(a), NULL);
	new_node = ft_lstnew(n);
	if (!new_node)
		return (ft_lstclear(a), NULL);
	ft_lstadd_back(a, new_node);
	return (*a);
}

void	ft_free_all(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	is_empty(char *str)
{
	int	n;
	int	i;

	i = 0; 
	n = 0;
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
int dupply(t_list *a)
{
	t_list *aux;
	int	num;	

	while (a)
	{
		num = a->value;
		aux = a;
		aux = aux->next;
		while (aux)
		{
			if (num == aux->value)
				return (1);
			aux = aux->next;
		}
		a = a->next;
	}
	return (0);
}