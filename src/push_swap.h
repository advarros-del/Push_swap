/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrvarga <adrvarga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 13:15:34 by adrvarga          #+#    #+#             */
/*   Updated: 2026/03/03 15:18:30 by adrvarga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# ifndef MAX_INT
#  define MAX_INT 2147483647
# endif
# ifndef MIN_INT
#  define MIN_INT -2147483648
# endif


typedef struct s_list
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_list	*next;
}	t_list;

void	push_swap(t_list *a);
t_list	**wtf_is_this(char **argv, int argc, t_list **a);
int		is_dg_or_sp(char *arg, int *s);
int		is_empty(char *str);
t_list	**send_to_list(long int n, t_list **a);
t_list	**gimmi_nbr(char *str, t_list **a);
void	ft_free_all(char **str, int i);
int		ft_atol(const char *nptr);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *str);
int		ft_lstsize(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(int content);
void	ft_lstclear(t_list **lst);
void	ft_lstdelone(t_list *lst);
int		dupply(t_list *a);
void 	three_args(t_list **a);
void	five_args(t_list **a, t_list **b);
int		is_sort(t_list *a);
int		find_min(t_list *a);
void 	radix_sort(t_list **a, t_list **b);
void	sa(t_list **x);
void	sb(t_list **x);
void	pa(t_list **bye, t_list **hey);
void	pb(t_list **bye, t_list **hey);
void	ra(t_list **x);
void	rb(t_list **x);
void	rr(t_list **x, t_list **y);
void	rra(t_list **x);
void	rrb(t_list **x);
void	rrr(t_list **x, t_list **y);
#endif
