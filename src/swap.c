/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gualvare <gualvare@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:03:08 by gualvare          #+#    #+#             */
/*   Updated: 2024/10/14 13:03:10 by gualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack **head)
{
	int		len;
	t_stack	*first;
	t_stack	*second;

	len = stack_len(*head);
	if (*head == NULL || len == 1)
		return ;
	first = *head;
	second = first->next;
	first->next = second->next;
	if (second->next != NULL)
		second->next->prev = first;
	first->prev = second;
	second->next = first;
	second->prev = NULL;
	*head = second;
}

void	sa(t_stack **a, bool print)
{
	swap(a);
	if (print)
		ft_printf("sa\n");
}

void	sb(t_stack **b, bool print)
{
	swap(b);
	if (print)
		ft_printf("sb\n");
}

void	ss(t_stack **a, t_stack **b, bool print)
{
	swap(a);
	swap(b);
	if (print)
		ft_printf("ss\n");
}
