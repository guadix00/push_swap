/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gualvare <gualvare@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:03:15 by gualvare          #+#    #+#             */
/*   Updated: 2024/10/14 13:12:49 by gualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_len(t_stack *stack)
{
	int	len;

	if (stack == NULL)
		return (0);
	len = 0;
	while (stack != NULL)
	{
		stack = stack->next;
		len++;
	}
	return (len);
}

t_stack	*find_last(t_stack *stack)
{
	t_stack	*last;

	last = stack;
	if (last == NULL)
		return (NULL);
	while (last->next != NULL)
		last = last->next;
	return (last);
}

void	innit_node(t_stack **stack, int num)
{
	t_stack	*new_node;
	t_stack	*last_node;

	if (stack == NULL)
		return ;
	new_node = malloc(sizeof(t_stack));
	if (new_node == NULL)
		return ;
	new_node->next = NULL;
	new_node->num = num;
	if (*stack == NULL)
	{
		*stack = new_node;
		new_node->prev = NULL;
	}
	else
	{
		last_node = find_last(*stack);
		last_node->next = new_node;
		new_node->prev = last_node;
	}
}

t_stack	*find_smallest(t_stack *stack)
{
	t_stack	*smallest;
	t_stack	*current_node;

	current_node = stack;
	if (current_node == NULL)
		return (NULL);
	smallest = current_node;
	while (current_node != NULL)
	{
		if (current_node->num < smallest->num)
			smallest = current_node;
		current_node = current_node->next;
	}
	return (smallest);
}

t_stack	*find_cheapest(t_stack *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack != NULL)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}
