/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrvarga <adrvarga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:50:08 by adrvarga          #+#    #+#             */
/*   Updated: 2026/02/16 16:59:52 by adrvarga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!new || !lst)
		return ;
	temp = ft_lstlast(*lst);
	if (temp == NULL)
	{
		*lst = new;
		return ;
	}
	temp->next = new;
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

int	ft_lstsize(t_list *lst)
{
	int		counter;

	counter = 0;
	while (lst)
	{
		lst = lst->next;
		counter++;
	}
	return (counter);
}

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}
