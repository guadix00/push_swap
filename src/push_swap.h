/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gualvare <gualvare@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:05:43 by gualvare          #+#    #+#             */
/*   Updated: 2024/10/14 13:06:20 by gualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# include "../libft/ft_printf.h"
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <stdbool.h>

typedef struct s_stack
{
	int				num;
	int				index;
	int				push_cost;
	bool			above_median;
	bool			cheapest;		
	struct s_stack	*next;
	struct s_stack	*prev;
	struct s_stack	*target_node;
}	t_stack;
long	ft_atol(char *str);
void	init_stack(t_stack **a, char *argv[], bool free_argv);
void	innit_node(t_stack **stack, int num);
void	pa(t_stack **a, t_stack **b, bool print);
void	pb(t_stack **b, t_stack **a, bool print);
void	sa(t_stack **a, bool print);
void	sb(t_stack **b, bool print);
void	ss(t_stack **a, t_stack **b, bool print);
void	ra(t_stack **a, bool print);
void	rb(t_stack **b, bool print);
void	rr(t_stack **a, t_stack **b, bool print);
void	rra(t_stack **a, bool print);
void	rrb(t_stack **b, bool print);
void	rrr(t_stack **a, t_stack **b, bool print);
void	bring_to_top(t_stack **stack, t_stack *top_node, char stack_name);
void	update_nodes(t_stack *a, t_stack *b);
t_stack	*find_last(t_stack *stack);
t_stack	*find_smallest(t_stack *stack);
bool	is_sorted(t_stack *stack);
int		stack_len(t_stack *stack);
void	set_index(t_stack *stack);
t_stack	*find_cheapest(t_stack *stack);
char	**split_arg(char const *s, char c);
void	free_arr(char *argv[]);
void	free_stack(t_stack	**stack);
void	error_free(t_stack **a, char *argv[], bool free_argv);
int		syntax_error(char *str);
int		dup_error(t_stack *a, int nbr);
void	sort_three(t_stack **a);
void	sort_stack(t_stack **a, t_stack **b);
#endif
