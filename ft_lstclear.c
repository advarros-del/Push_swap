/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrvarga <adrvarga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 12:17:20 by adrvarga          #+#    #+#             */
/*   Updated: 2026/01/28 16:04:08 by adrvarga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*aux;
	t_list	*temp;

	if (!lst || !*lst)
		return ;
	temp = *lst;
	while (temp != NULL)
	{
		aux = temp->next;
		ft_lstdelone(temp);
		temp = aux;
	}
	*lst = NULL;
}

void	ft_lstdelone(t_list *lst)
{
	free(lst->content);
	free(lst);
}
