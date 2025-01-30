/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igngonza <igngonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:07:41 by igngonza          #+#    #+#             */
/*   Updated: 2025/01/29 10:29:50 by igngonza         ###   ########.fr       */
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
	t_list	*head;
	int		distance;

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

void	free_stack(t_list **stack)
{
	t_list *head;
	t_list *tmp;

	head = *stack;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	free(stack);
}