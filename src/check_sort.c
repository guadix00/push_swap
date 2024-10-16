/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gualvare <gualvare@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:09:37 by gualvare          #+#    #+#             */
/*   Updated: 2024/10/14 13:13:06 by gualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sorted(t_stack *stack)
{
	if (stack == NULL)
		return (1);
	while (stack->next)
	{
		if (stack->num > stack->next->num)
			return (false);
		stack = stack->next;
	}
	return (true);
}

static t_stack	*find_highest(t_stack *stack)
{
	t_stack	*highest_node;

	if (stack == NULL)
		return (NULL);
	highest_node = stack;
	while (stack != NULL)
	{
		if (stack->num > highest_node->num)
			highest_node = stack;
		stack = stack->next;
	}
	return (highest_node);
}

void	sort_three(t_stack **a)
{
	t_stack	*highest_node;

	if (*a == NULL)
		return ;
	highest_node = find_highest(*a);
	if (highest_node == *a)
		ra(a, true);
	else if (highest_node == (*a)->next)
		rra(a, true);
	if ((*a)->num > (*a)->next->num)
		sa(a, true);
}
