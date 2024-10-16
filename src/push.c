/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gualvare <gualvare@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:11:34 by gualvare          #+#    #+#             */
/*   Updated: 2024/10/14 13:11:36 by gualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **dest, t_stack **src)
{
	t_stack	*pushed_node;
	t_stack	*src_first;
	t_stack	*dest_first;

	src_first = *src;
	dest_first = *dest;
	if (src_first == NULL)
		return ;
	pushed_node = src_first;
	*src = src_first->next;
	if (*src != NULL)
		(*src)->prev = NULL;
	pushed_node->prev = NULL;
	if (dest_first == NULL)
	{
		*dest = pushed_node;
		pushed_node->next = NULL;
	}
	else
	{
		pushed_node->next = dest_first;
		pushed_node->next->prev = pushed_node;
		*dest = pushed_node;
	}
}

void	pa(t_stack **a, t_stack **b, bool print)
{
	push(a, b);
	if (print)
		ft_printf("pa\n");
}

void	pb(t_stack **b, t_stack **a, bool print)
{
	push(b, a);
	if (print)
		ft_printf("pb\n");
}
