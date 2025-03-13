/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igngonza <igngonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:58:31 by igngonza          #+#    #+#             */
/*   Updated: 2025/03/13 11:58:30 by igngonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

// Stack
typedef struct s_list
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_list	*next;
}					t_list;

/* Initialization */
void				init_stack(t_list **stack, int argc, char **argv);
void				index_stack(t_list *stack, int stack_size);

/* Algorithms */
int					sorted_stack_checker(t_list **stack);
void				tiny_sort(t_list **stack);
void				sort(t_list **stack_a, t_list **stack_b);

/* Position */
int					find_lowest_index_position(t_list **stack);
void				assign_target_positions(t_list **stack_a, t_list **stack_b);

/* Cost */
void				calculate_costs(t_list **stack_a, t_list **stack_b);
void				execute_cheapest_move(t_list **stack_a, t_list **stack_b);

/* Calculate Move */
void				do_move(t_list **a, t_list **b, int cost_a, int cost_b);

/* Stack Functions */
void				ft_lstadd_back(t_list **stack, t_list *new);
int					get_stack_size(t_list *head);
t_list				*get_stack_bottom(t_list *stack);
t_list				*get_stack_before_bottom(t_list *stack);
t_list				*ft_lstnew(long value);
t_list				*ft_lstlast(t_list *head);

/* Input Check */
int					check_args(int argc, char **argv);
int					is_digit(int c);
int					nbstr_cmp(const char *s1, const char *s2);
int					is_sign(char c);
void				free_split(char **strs);

/* Utils */
char				**ft_split(char const *s, char c);
long				ft_atoi(const char *str);
void				ft_putstr(char *str);
void				free_stack(t_list **stack);
void				ft_free(char **str);
int					abs(int nb);

// Instruction functions
void				pa(t_list **stack_a, t_list **stack_b);
void				pb(t_list **stack_a, t_list **stack_b);
void				sa(t_list **stack_a);
void				sb(t_list **stack_b);
void				ss(t_list **stack_a, t_list **stack_b);
void				ra(t_list **stack_a);
void				rb(t_list **stack_b);
void				rr(t_list **stack_a, t_list **stack_b);
void				rra(t_list **stack_a);
void				rrb(t_list **stack_b);
void				rrr(t_list **stack_a, t_list **stack_b);

/* Error */
void				exit_error(t_list **stack_a, t_list **stack_b);

#endif