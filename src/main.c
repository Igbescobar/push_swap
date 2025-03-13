/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igngonza <igngonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:01:30 by igngonza          #+#    #+#             */
/*   Updated: 2025/03/13 09:38:16 by igngonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_list **stack, int argc, char **argv)
{
	int		i;
	char	**args;
	t_list	*new;

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		new = ft_lstnew(ft_atoi(args[i]));
		ft_lstadd_back(stack, new);
		i++;
	}
	if (argc == 2)
		free_split(args);
}

void	sort_stack(t_list **stack_a, t_list **stack_b, int stack_size)
{
	if (sorted_stack_checker(stack_a))
	{
		free_stack(stack_a);
		free_stack(stack_b);
	}
	else if (stack_size == 2)
		sa(stack_a);
	else if (stack_size == 3)
		tiny_sort(stack_a);
	else if (stack_size > 3)
		sort(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;
	int		stack_size;

	if (argc < 2)
		return (0);
	if (!check_args(argc, argv))
		exit_error(NULL, NULL);
	stack_a = (t_list **)malloc(sizeof(t_list *));
	stack_b = (t_list **)malloc(sizeof(t_list *));
	*stack_a = NULL;
	*stack_b = NULL;
	init_stack(stack_a, argc, argv);
	stack_size = get_stack_size(*stack_a);
	index_stack(*stack_a, stack_size + 1);
	sort_stack(stack_a, stack_b, stack_size);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
