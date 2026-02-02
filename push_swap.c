/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrvarga <adrvarga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 18:42:45 by adrvarga          #+#    #+#             */
/*   Updated: 2026/02/02 19:55:21 by adrvarga         ###   ########.fr       */
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
	group_on_b(a, b);
	sort_b(a, b);
	return (a);
}

void	sort_b(t_list **a, t_list **b)
{
	int	minimun;
	int	indx_a;
	int	indx_b;
	t_list	*temp;
	int	aux;

	temp = (*a);
	while ((*a)->next != NULL)
	{
		mv_calculator(&a, &b);
		minimun = (*a)->mv;
		while ((*a)->next != NULL)
		{
			if (minimun <= (*a)->mv)
				minimun = (*a)->mv;
			a = a->next;
		}
		(*a) = temp;
		while (minimun != (*a)->mv)
			a = a->next;
		aux = (*a)->content;
		while ((*b)->next != NULL)
			if (aux < (*b)->content)
				*b = (*b)->next;
		//comprovamos que el index de a y b son menores que la mitad del index total respectivamente		
		if (b->index <= ft_lstsize(*b) / 2 && b->index != 1	&& b->index != 2
			&& a->index <= ft_lstsize(*b) / 2 && a->index != 1	&& a->index != 2)
		{
			aux = b->index - a->index;
			if (aux < 0)
				aux = aux * -1;
			while (aux != 0)
			{
				rotating(&a);
				rotating(&b);
				write(1, "rr", 2);
				aux--;				
			}
		}
		//comprovamos que el index de a y b son mayores que la mitad del index total respectivamente		
		else if (b->index > ft_lstsize(*b) / 2 && b->index != 1	&& b->index != 2
			&& a->index > ft_lstsize(*b) / 2 && a->index != 1	&& a->index != 2)
		{
			aux = b->index - a->index;
			if (aux < 0)
				aux = aux * -1;
			while (aux != 0)
			{
				rerotating(&a);
				rerotating(&b);
				write(1, "rrr", 2);
				aux--;				
			}
		}
		//preparamos b
		else if(b->index != 2)
		{
			swapeanding(&b);
			write(1, "sb", 2);
		}
		else if (b->index <= ft_lstsize(*b) / 2 && b->index != 1 && b->index != 2)
		{
			while (indx_b -1 != 0)
			{
				rotating(&b);
				indx_b--;
				write (1, "rb", 2);
			}
		}
		else if (b->index > ft_lstsize(*b) / 2 && b->index != ft_lstsize(*b))
		{
			while (indx_b -1 != 0)
			{
				rerotating(&b);
				indx_b--;
				write (1, "rrb", 3);
			}
		}
		//preparamos b
		else if (a->index <= ft_lstsize(*a) / 2 && a->index != 1 && a->index != 2)
		{
			while (indx_b -1 != 0)
			{
				rotating(&b);
				indx_b--;
				write (1, "rb", 2);
			}
		}
		else if(a->index != 2)
		{
			swapeanding(&a);
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
		/*else if (b-> index == NULL) AQUI QUIERO COMPROBAR SI ES EL ULTIMO DE B. APUNTA A NULL??
		{
			ro
		}*/
		a = temp;
	}
}
void	group_on_b(t_list **a, t_list **b)
{
	int index;
	int	counter;
	
	index = 0;
	put_the_index(&a);
	counter = bigger_group(a, &index);
	while (counter != 0)
	{
		while ((*a)->index != index)
		{
			rotating(&a);
			write(1, "ra", 2);
		}
		pushing(&a, &b);
		write (1, "pa", 2);
		counter--;
	}
}
