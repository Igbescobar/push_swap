/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igngonza <igngonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:47:41 by igngonza          #+#    #+#             */
/*   Updated: 2025/01/29 12:23:16 by igngonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_bits(t_list **stack)
{
	t_list	*head;
	int		max_index;
	int		max_bits;

	max_index = 0;
	max_bits = 0;
	head = *stack;
	while (head)
	{
		if (head->index > max_index)
			max_index = head->index;
		head = head->next;
	}
	while ((max_index >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_list **stack_a, t_list **stack_b)
{
	int		max_bits;
	int		i;
	int		j;
	int		stack_length;
	t_list	*head;

	head = *stack_a;
	stack_length = ft_lstsize(stack_a);
	max_bits = get_max_bits(stack_a);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j++ < stack_length)
		{
			head = *stack_a;
			if (((head->index >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
		}
		while (ft_lstsize(stack_b) != 0)
			pa(stack_a, stack_b);
		i++;
	}
}
