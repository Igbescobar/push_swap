/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_simple.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igngonza <igngonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:45:29 by igngonza          #+#    #+#             */
/*   Updated: 2025/01/28 11:21:42 by igngonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_list **stack_a)
{
	t_list	*first;
	t_list	*second;

	if (!stack_a || ft_lstsize(stack_a) < 2)
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
	min = head->value;
	while (head->next)
	{
		if (head->next->index < min && head->next->index != val)
			min = head->next->index;
		head = head->next;
	}
	return (min);
}

int	rotate(t_list **stack)
{
	t_list	*head;
	t_list	*tail;

	if (ft_lstsize(stack) < 2)
		return (-1);
	head = *stack;
	tail = ft_lstlast(head);
	*stack = head->next;
	head->next = NULL;
	tail->next = head;
	return (1);
}

int	reverseRotate(t_list **stack)
{
	t_list	*head;
	t_list	*tail;

	if (ft_lstsize(stack) < 2)
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
	t_list *tmp;
	t_list *head_to;
	t_list *head_from;

	if (ft_lstsize(stack_from) == 0)
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