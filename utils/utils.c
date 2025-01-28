/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igngonza <igngonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:07:41 by igngonza          #+#    #+#             */
/*   Updated: 2025/01/27 16:52:52 by igngonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list **stack_a)
{
	t_list	*head;

	head = *stack_a;
	while (head->next)
	{
		if (head->value > head->next->value)
			return (0);
		head = head->next;
	}
	return (1);
}

int	find_distance(t_list **stack_a, int index)
{
	t_list *head;
	int distance;

	distance = 0;
	head = *stack_a;
	while (head)
	{
		if (head->index == index)
			break ;
		++distance;
		head = head->next;
	}
	return (distance);
}