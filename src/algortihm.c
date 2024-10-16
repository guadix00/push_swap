/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gualvare <gualvare@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:02:55 by gualvare          #+#    #+#             */
/*   Updated: 2024/10/14 13:33:17 by gualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_both_cheapest(t_stack **a, t_stack **b,
							t_stack *cheapest_node, char above_median)
{
	while (*a != cheapest_node->target_node && *b != cheapest_node)
	{
		if (above_median == 'T')
			rr(a, b, true);
		else if (above_median == 'F')
			rrr(a, b, true);
	}
	set_index(*a);
	set_index(*b);
}

void	bring_to_top(t_stack **stack, t_stack *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack, true);
			else
				rra(stack, true);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack, true);
			else
				rrb(stack, true);
		}
	}
}

static void	push_b_to_a(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;

	cheapest_node = find_cheapest(*b);
	if (!cheapest_node || !cheapest_node->target_node)
		return ;
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		move_both_cheapest(a, b, cheapest_node, 'T');
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
		move_both_cheapest(a, b, cheapest_node, 'F');
	bring_to_top(b, cheapest_node, 'b');
	bring_to_top(a, cheapest_node->target_node, 'a');
	pa(a, b, true);
}

static void	smallest_on_top(t_stack **a)
{
	while ((*a)->num != find_smallest(*a)->num)
	{
		if (find_smallest(*a)->above_median)
			ra(a, true);
		else
			rra(a, true);
	}
}

void	sort_stack(t_stack **a, t_stack **b)
{
	int	len_a;

	len_a = stack_len(*a);
	if (len_a-- > 3)
		pb(b, a, true);
	if (len_a-- > 3)
		pb(b, a, true);
	while (len_a-- > 3)
		pb(b, a, true);
	sort_three(a);
	while (*b)
	{
		update_nodes(*a, *b);
		push_b_to_a(a, b);
	}
	set_index(*a);
	smallest_on_top(a);
}
