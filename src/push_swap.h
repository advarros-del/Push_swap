/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrvarga <adrvarga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 13:15:34 by adrvarga          #+#    #+#             */
/*   Updated: 2026/02/25 19:05:24 by adrvarga         ###   ########.fr       */
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
	int				content;
	int				index;
	int				mv;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

t_list	*push_swap(char **argv, int argc);
t_list	**wtf_is_this(char **argv, int argc, t_list **a);
int		is_dg_or_sp(int c, int *s);
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
int		is_sort(t_list *a);
void	is_bigger(int *counter, int *c, int *index, int *temp_index);
int		bigger_group(t_list *a, int *index);
void	sort_b(t_list **a, t_list **b);
void	put_the_index(t_list **x);
void	mv_calculator(t_list **a, t_list **b);
void	calculate_b(t_list *node_a, t_list **b, int *mv_b);
int		find_and_set_b(t_list **b, t_list **node_b, int value, int *code_mv);
int		check_and_mv_both(t_list **a, t_list **b, t_list *node_a, t_list *node_b);
void	min_mv(t_list **a, int *minimun);
void	group_on_b(t_list **a, t_list **b);
int		check_mv(int a, int b);
void	prepare_b(t_list *node_b, t_list **b, int *the_move, int *code_mv);
void	prepare_and_send_a(t_list **a, t_list **b,t_list *node_a);
void	resort_b(t_list **b, int the_move, int code_mv);
void	is_rotating_a(int *indx_a, t_list **a);
void	is_rotating_b(int *indx_b, t_list **b, int *the_move, int *code_mv);
void	is_rerotating_a(int *indx_a, t_list **a);
void	is_rotating_all(t_list **a, t_list **b, t_list *node_a, t_list *node_b);
void	is_rerotating_all(t_list **a, t_list **b, t_list *node_a, t_list *node_b);
void	swapeanding(t_list **x);
void	pushing(t_list **bye, t_list **hey);
void	rotating(t_list **x);
void	rerotating(t_list **x);

#endif
