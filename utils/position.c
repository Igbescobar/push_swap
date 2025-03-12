/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igngonza <igngonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 07:50:19 by igngonza          #+#    #+#             */
/*   Updated: 2025/03/12 11:20:50 by igngonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	assign_positions(t_list **stack)
{
	t_list	*current;
	int		position;

	current = *stack;
	position = 0;
	while (current)
	{
		current->pos = position;
		current = current->next;
		position++;
	}
}

int	find_lowest_index_position(t_list **stack)
{
	t_list	*current;
	int		lowest_index;
	int		lowest_pos;

	current = *stack;
	lowest_index = 2147483647;
	assign_positions(stack);
	lowest_pos = current->pos;
	while (current)
	{
		if (current->index < lowest_index)
		{
			lowest_index = current->index;
			lowest_pos = current->pos;
		}
		current = current->next;
	}
	return (lowest_pos);
}

static int	find_target_position(t_list **a, int b_idx, int target_idx,
		int target_pos)
{
	t_list	*current_a;

	current_a = *a;
	while (current_a)
	{
		if (current_a->index > b_idx && current_a->index < target_idx)
		{
			target_idx = current_a->index;
			target_pos = current_a->pos;
		}
		current_a = current_a->next;
	}
	if (target_idx != 2147483647)
		return (target_pos);
	current_a = *a;
	while (current_a)
	{
		if (current_a->index < target_idx)
		{
			target_idx = current_a->index;
			target_pos = current_a->pos;
		}
		current_a = current_a->next;
	}
	return (target_pos);
}

void	assign_target_positions(t_list **stack_a, t_list **stack_b)
{
	t_list	*current_b;
	int		target_pos;

	current_b = *stack_b;
	assign_positions(stack_a);
	assign_positions(stack_b);
	target_pos = 0;
	while (current_b)
	{
		target_pos = find_target_position(stack_a, current_b->index, 2147483647,
				target_pos);
		current_b->target_pos = target_pos;
		current_b = current_b->next;
	}
}
