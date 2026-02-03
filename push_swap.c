/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrvarga <adrvarga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 18:42:45 by adrvarga          #+#    #+#             */
/*   Updated: 2026/02/03 17:24:18 by adrvarga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*push_swap(char **argv, int argc)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	wtf_is_this(argv, argc, &a);
	if (a == NULL)
	{
		write(2, "Error\n", 6);
		return (NULL);
	}
	group_on_b(&a, &b);
	sort_b(&a, &b);
	return (a);
}
void	group_on_b(t_list **a, t_list **b)
{
	int index;
	int	counter;
	t_list	*node_a;
	
	node_a = *a;
	index = 0;
	put_the_index(a);
	counter = bigger_group(*a, &index);
	while (counter != 0)
	{
		while (node_a->index != index)
		{
			rotating(a);
			write(1, "ra", 2);
		}
		pushing(a, b);
		write (1, "pa", 2);
		counter--;
	}
}
void	sort_b(t_list **a, t_list **b)
{
	int	minimun;
	t_list	*node_a;
	t_list	*node_b;

	node_b = *b;
	node_a = *a;
	while ((*a)->next != NULL)
	{
		mv_calculator(*a, *b);
		min_mv(a, minimun);
		while (minimun != node_a->mv)
			node_a = node_a->next;
		while (node_b->next != NULL)
			if (node_a->content < node_b->content)
				node_b = node_b->next;
		check_and_mv_both(a, b, node_a, node_b);
		prepare_b(node_b, b);
		prepare_and_send_a(a, b, node_a, node_b);
		/*else if (b-> index == NULL) AQUI QUIERO COMPROBAR SI ES EL ULTIMO DE B. APUNTA A NULL??*/
	}
} 
void	min_mv(t_list **a, int minimun)
{
	t_list *node_a;
	
	node_a = *a;
	minimun = node_a->mv;
		while (node_a->next != NULL)
		{
			if (minimun <= node_a->mv)
				minimun = node_a->mv;
			node_a = node_a->next;
		}
}
void	check_and_mv_both(t_list **a, t_list **b, t_list *node_a, t_list *node_b)
{
	int	aux;
	
	if (node_b->index <= ft_lstsize(node_b) / 2 && node_b->index != 1 && node_b->index != 2
		&& node_a->index <= ft_lstsize(node_b) / 2 && node_a->index != 1 && node_a->index != 2)
	{
		aux = node_b->index - node_a->index;
		if (aux < 0)
			aux = aux * -1;
		while (aux != 0)
		{
			rotating(a);
			rotating(b);
			write(1, "rr", 2);
			aux--;				
		}
	}
	else if (node_b->index > ft_lstsize(node_b) / 2 && node_b->index != 1	&& node_b->index != 2
				&& node_a->index > ft_lstsize(node_b) / 2 && node_a->index != 1	&& node_a->index != 2)
	{
		aux = node_b->index - node_a->index;
		if (aux < 0)
			aux = aux * -1;
		while (aux != 0)
		{
			rerotating(a);
			rerotating(b);
			write(1, "rrr", 2);
			aux--;				
		}
	}
}
void	prepare_b(t_list *node_b, t_list **b)
{
	int	indx_b;
	
	if(node_b->index == 2)
	{
		swapeanding(b);
		write(1, "sb", 2);
	}
	else if (node_b->index <= ft_lstsize(*b) / 2 && node_b->index != 1 && node_b->index != 2)
	{
		while (indx_b -1 != 0)
		{
			rotating(b);
			indx_b--;
			write (1, "rb", 2);
		}
	}
	else if (node_b->index > ft_lstsize(*b) / 2 && node_b->index != ft_lstsize(*b))
	{
		while (indx_b -1 != 0)
		{
			rerotating(b);
			indx_b--;
			write (1, "rrb", 3);
		}
	}
}
void	prepare_and_send_a(t_list **a, t_list **b, t_list *node_a, t_list *node_b)
{
	int	indx_a;
	
	if (node_a->index <= ft_lstsize(*a) / 2 && node_a->index != 1 && node_a->index != 2)
	{
		while (indx_a -1 != 0)
		{
			rotating(b);
			indx_a--;
			write (1, "rb", 2);
		}
	}
	else if(node_a->index == 2)
	{
		swapeanding(a);
		write(1, "sa", 2);
	}
	else if (a->index > ft_lstsize(*a) / 2 && a->index != ft_lstsize(*a))
	{
		while (indx_a -1 != 0)
		{
			rerotating(&a);
			indx_a--;
			write (1, "rra", 3);
		}
	}
}
