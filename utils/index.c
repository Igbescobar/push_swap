/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igngonza <igngonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:46:32 by igngonza          #+#    #+#             */
/*   Updated: 2025/03/11 11:49:48 by igngonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_stack(t_list *stack_a, int stack_size)
{
	t_list	*ptr;
	t_list	*highest;
	int		value;

	while (--stack_size > 0)
	{
		ptr = stack_a;
		value = -2147483648;
		highest = NULL;
		while (ptr)
		{
			if (ptr->value == -2147483648 && ptr->index == 0)
				ptr->index = 1;
			else if (ptr->value > value && ptr->index == 0)
			{
				value = ptr->value;
				highest = ptr;
			}
			ptr = ptr->next;
		}
		if (highest != NULL)
			highest->index = stack_size;
	}
}
