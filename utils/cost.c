/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igngonza <igngonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:28:20 by igngonza          #+#    #+#             */
/*   Updated: 2025/03/11 15:10:00 by igngonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calculate_costs(t_list **stack_a, t_list **stack_b)
{
	t_list	*current_b;
	int		size_a;
	int		size_b;

	size_a = get_stack_size(*stack_a);
	size_b = get_stack_size(*stack_b);
	current_b = *stack_b;
	while (current_b)
	{
		current_b->cost_b = current_b->pos;
		if (current_b->pos > size_b / 2)
			current_b->cost_b = (size_b - current_b->pos) * -1;
		current_b->cost_a = current_b->target_pos;
		if (current_b->target_pos > size_a / 2)
			current_b->cost_a = (size_a - current_b->target_pos) * -1;
		current_b = current_b->next;
	}
}

void	execute_cheapest_move(t_list **stack_a, t_list **stack_b)
{
	t_list	*current_b;
	int		lowest_cost;
	int		cost_a;
	int		cost_b;

	current_b = *stack_b;
	lowest_cost = 2147483647;
	while (current_b)
	{
		if (abs(current_b->cost_a) + abs(current_b->cost_b) < abs(lowest_cost))
		{
			lowest_cost = abs(current_b->cost_b) + abs(current_b->cost_a);
			cost_a = current_b->cost_a;
			cost_b = current_b->cost_b;
		}
		current_b = current_b->next;
	}
	do_move(stack_a, stack_b, cost_a, cost_b);
}
