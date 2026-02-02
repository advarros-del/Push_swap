/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrvarga <adrvarga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 13:15:34 by adrvarga          #+#    #+#             */
/*   Updated: 2026/02/02 19:08:54 by adrvarga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				*content;
	int				index;
	int				mv;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

t_list	**wtf_is_this(char **argv, int argc, t_list **a);
t_list	**send_to_list(int n, t_list **a);
t_list	**gimmi_nbr(char *str, t_list **a);
void	ft_free_all(char **str, int i);
void	swapeanding(t_list **x);
void	pushing(t_list **bye, t_list **hey);
void	rotating(t_list **x);
void	rerotating(t_list **x);
int		is_dg_or_sp(int c, int *s);
int		ft_atoi(const char *nptr);
char	**ft_split(char const *s, char c);
void	plus_index(t_list *x);
void	minus_index(t_list *x);
int		ft_lstsize(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(void *content);
void	ft_lstclear(t_list **lst);
void	ft_lstdelone(t_list *lst);
void	put_the_index(t_list **x);
void	calculate_b(t_list *node_a, t_list **b, int *mv_b);
void	sort_b(t_list **a, t_list **b);
int		bigger_group(t_list *a, int *index);
void	mv_calculator(t_list *a, t_list *b);
void	calculate_b(t_list *node_a, t_list **b, int *mv_b);
void	put_the_index(t_list **x);

#endif