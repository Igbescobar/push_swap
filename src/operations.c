/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igngonza <igngonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:33:38 by igngonza          #+#    #+#             */
/*   Updated: 2025/01/30 10:54:29 by igngonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	sa(t_list **stack_a)
{
	if (!swap(stack_a))
		return (-1);
	ft_putendl_fd("sa", 1);
	return (0);
}

int	ra(t_list **stack_a)
{
	if (!rotate(stack_a))
		return (-1);
	ft_putendl_fd("ra", 1);
	return (0);
}

int	rra(t_list **stack_a)
{
	if (!reverse_rotate(stack_a))
		return (-1);
	ft_putendl_fd("rra", 1);
	return (0);
}

int	pb(t_list **stack_a, t_list **stack_b)
{
	if (!push(stack_b, stack_a))
		return (-1);
	ft_putendl_fd("pb", 1);
	return (0);
}

int	pa(t_list **stack_a, t_list **stack_b)
{
	if (!push(stack_a, stack_b))
		return (-1);
	ft_putendl_fd("pa", 1);
	return (0);
}
