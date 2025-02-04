/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igngonza <igngonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:25:46 by igngonza          #+#    #+#             */
/*   Updated: 2025/01/31 11:07:57 by igngonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	sort_3(t_list **stack_a)
{
	int	max_index;

	max_index = find_largest_index(*stack_a);
	if ((*stack_a)->index == max_index)
		ra(stack_a);
	else if ((*stack_a)->next->index == max_index)
		rra(stack_a);
	if ((*stack_a)->index > (*stack_a)->next->index)
		sa(stack_a);
}

void	sort_4(t_list **stack_a, t_list **stack_b)
{
	int	distance;

	distance = find_distance(stack_a, get_min_index(stack_a, -1));
	if (distance == 1)
		ra(stack_a);
	else if (distance == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (distance == 3)
		rra(stack_a);
	if (sorted_stack_checker(stack_a))
		return ;
	pb(stack_a, stack_b);
	sort_3(stack_a);
	pa(stack_a, stack_b);
}

void	sort_5(t_list **stack_a, t_list **stack_b)
{
	int	distance;

	distance = find_distance(stack_a, get_min_index(stack_a, -1));
	if (distance == 1)
		ra(stack_a);
	if (distance == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	if (distance == 3)
	{
		rra(stack_a);
		rra(stack_a);
	}
	if (distance == 4)
		rra(stack_a);
	if (sorted_stack_checker(stack_a))
		return ;
	pb(stack_a, stack_b);
	sort_4(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	simple_sort(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = stack_size(stack_a);
	if (sorted_stack_checker(stack_a) || size == 0 || size == 1)
		return ;
	if (size == 2)
		sa(stack_a);
	else if (size == 3)
		sort_3(stack_a);
	else if (size == 4)
		sort_4(stack_a, stack_b);
	else if (size == 5)
		sort_5(stack_a, stack_b);
}
