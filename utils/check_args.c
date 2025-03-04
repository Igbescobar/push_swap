/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igngonza <igngonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:47:28 by igngonza          #+#    #+#             */
/*   Updated: 2025/03/04 19:26:59 by igngonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isnum(char *num)
{
	int		i;
	long	val;

	i = 0;
	if (is_sign(num[i]) && num[i + 1] != '\0')
		i++;
	while (num[i] && is_digit(num[i]))
		i++;
	if (num[i] != '\0' && !is_digit(num[i]))
		return (0);
	val = ft_atoi(num);
	if (val > INT_MAX || val < INT_MIN)
		return (0);
	return (1);
}

int	ft_contains(int tmp, char **args, int i)
{
	i++;
	while (args[i])
	{
		if (ft_atoi(args[i]) == tmp)
			return (1);
		i++;
	}
	return (0);
}

static int	validate_args(char **args, int start, int argc)
{
	long	tmp;
	int		i;

	(void)argc;
	i = start;
	while (args[i])
	{
		tmp = ft_atoi(args[i]);
		if (!ft_isnum(args[i]) || ft_contains(tmp, args, i) || tmp < INT_MIN
			|| tmp > INT_MAX)
			return (0);
		i++;
	}
	return (1);
}

int	check_args(int argc, char **argv)
{
	char	**args;
	int		i;
	int		valid;

	if (argc == 2)
	{
		if (argv[1][0] == '\0' || argv[1][0] == '-')
			return (0);
		args = ft_split(argv[1], ' ');
		if (!args)
			return (0);
		i = 0;
	}
	else
	{
		args = argv;
		i = 1;
	}
	valid = validate_args(args, i, argc);
	if (argc == 2)
		free_split(args);
	return (valid);
}
