/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_simple.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igngonza <igngonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:45:29 by igngonza          #+#    #+#             */
/*   Updated: 2025/01/30 12:28:54 by igngonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_list **stack_a)
{
	t_list	*first;
	t_list	*second;

	if (!stack_a || stack_size(stack_a) < 2)
		return (-1);
	first = *stack_a;
	second = first->next;
	if (!first || !second)
		ft_error("Error ocurred while swapping");
	first->next = second->next;
	second->next = first;
	*stack_a = second;
	return (1);
}

int	get_min_index(t_list **stack_a, int val)
{
	t_list	*head;
	int		min;

	head = *stack_a;
	min = head->index;
	while (head->next)
	{
		head = head->next;
		if ((head->index < min) && (head->index != val))
			min = head->index;
	}
	return (min);
}

int	rotate(t_list **stack)
{
	t_list	*head;
	t_list	*tail;

	if (stack_size(stack) < 2)
		return (-1);
	head = *stack;
	tail = ft_lstlast(head);
	*stack = head->next;
	head->next = NULL;
	tail->next = head;
	return (1);
}

int	reverse_rotate(t_list **stack)
{
	t_list	*head;
	t_list	*tail;

	if (stack_size(stack) < 2)
		return (-1);
	head = *stack;
	tail = ft_lstlast(head);
	while (head)
	{
		if (head->next->next == NULL)
		{
			head->next = NULL;
			break ;
		}
		head = head->next;
	}
	tail->next = *stack;
	*stack = tail;
	return (1);
}

int	push(t_list **stack_to, t_list **stack_from)
{
	t_list	*tmp;
	t_list	*head_to;
	t_list	*head_from;

	if (stack_size(stack_from) == 0)
		return (-1);
	head_from = *stack_from;
	head_to = *stack_to;
	tmp = head_from;
	head_from = head_from->next;
	*stack_from = head_from;
	if (!head_to)
	{
		head_to = tmp;
		head_to->next = NULL;
		*stack_to = head_to;
	}
	else
	{
		tmp->next = head_to;
		*stack_to = tmp;
	}
	return (1);
}
