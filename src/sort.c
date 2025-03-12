/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igngonza <igngonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:47:41 by igngonza          #+#    #+#             */
/*   Updated: 2025/03/12 11:06:39 by igngonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_all_save_three(t_list **stack_a, t_list **stack_b)
{
	int	stack_size;
	int	half_stack_size;
	int	pushed;
	int	i;

	stack_size = get_stack_size(*stack_a);
	half_stack_size = stack_size / 2;
	pushed = 0;
	i = 0;
	while (i < stack_size && pushed < half_stack_size)
	{
		if ((*stack_a)->index <= half_stack_size)
		{
			pb(stack_a, stack_b);
			pushed++;
		}
		else
			ra(stack_a);
		i++;
	}
	while (stack_size - pushed > 3)
	{
		pb(stack_a, stack_b);
		pushed++;
	}
}

static void	shift_stack(t_list **stack_a)
{
	int	lowest_pos;
	int	stack_size;

	stack_size = get_stack_size(*stack_a);
	lowest_pos = find_lowest_index_position(stack_a);
	if (lowest_pos > stack_size / 2)
	{
		while (lowest_pos < stack_size)
		{
			rra(stack_a);
			lowest_pos++;
		}
	}
	else
	{
		while (lowest_pos > 0)
		{
			ra(stack_a);
			lowest_pos--;
		}
	}
}

void	sort(t_list **stack_a, t_list **stack_b)
{
	push_all_save_three(stack_a, stack_b);
	tiny_sort(stack_a);
	while (*stack_b)
	{
		assign_target_positions(stack_a, stack_b);
		calculate_costs(stack_a, stack_b);
		execute_cheapest_move(stack_a, stack_b);
	}
	if (!sorted_stack_checker(stack_a))
		shift_stack(stack_a);
}
