/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gualvare <gualvare@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:06:55 by gualvare          #+#    #+#             */
/*   Updated: 2024/10/14 13:07:52 by gualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_index(t_stack *stack)
{
	int	i;
	int	median;

	i = 0;
	if (stack == NULL)
		return ;
	median = stack_len(stack) / 2;
	while (stack != NULL)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

static void	set_target_nodes(t_stack *a, t_stack *b)
{
	t_stack	*current_a;
	t_stack	*target_node;
	int		temp_target_value;

	while (b)
	{
		target_node = NULL;
		temp_target_value = INT_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->num > b->num && current_a->num < temp_target_value)
			{
				temp_target_value = current_a->num;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (temp_target_value == INT_MAX)
			b->target_node = find_smallest(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

static void	set_cost(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (b)
	{
		b->push_cost = b->index;
		if (!b->above_median)
			b->push_cost = len_b - b->index;
		if (!b->target_node->above_median)
			b->push_cost += len_a - b->target_node->index;
		else
			b->push_cost += b->target_node->index;
		b = b->next;
	}
}

static void	set_cheapest(t_stack *b)
{
	t_stack	*cheapest_node;
	t_stack	*current_b;

	if (b == NULL)
		return ;
	cheapest_node = b;
	current_b = b;
	while (current_b)
	{
		if (current_b->push_cost < cheapest_node->push_cost)
			cheapest_node = current_b;
		current_b = current_b->next;
	}
	current_b = b;
	while (current_b)
	{
		current_b->cheapest = false;
		current_b = current_b->next;
	}
	cheapest_node->cheapest = true;
}

void	update_nodes(t_stack *a, t_stack *b)
{
	set_index(a);
	set_index(b);
	set_target_nodes(a, b);
	set_cost(a, b);
	set_cheapest(b);
}
