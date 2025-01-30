/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igngonza <igngonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:58:31 by igngonza          #+#    #+#             */
/*   Updated: 2025/01/29 11:37:00 by igngonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <fcntl.h>
# include <limits.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// Stack
typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
}					t_list;

// Util functions
t_list				*ft_lstnew(long value);
t_list				*ft_lstlast(t_list *head);
void				ft_lstadd_back(t_list **stack, t_list *new);
void				print_stack(t_list *head);
int					ft_lstsize(t_list **head);
char				**ft_split(char const *s, char c);
long				ft_atoi(const char *str);
int					ft_isnum(char *num);
int					ft_contains(int tmp, char **args, int i);
int					ft_isdigit(int c);
void				ft_putendl_fd(char *str, int fd);
void				ft_putstr_fd(const char *str, int fd);
void				ft_putchar_fd(char c, int fd);

void				ft_error(char *msg);
void				ft_check_args(int argc, char **argv);
int					is_sorted(t_list **stack);
int					find_distance(t_list **stack, int index);
int					get_min_index(t_list **stack_a, int val);
void				free_stack(t_list **stack);
void				ft_free(char **str);

// Algorithm utils
void				radix_sort(t_list **stack_a, t_list **stack_b);
void				simple_sort(t_list **stack_a, t_list **stack_b);
void				index_stack(t_list **stack);
void				sort_5(t_list **stack_a, t_list **stack_b);

// Instruction functions
int					swap(t_list **stack);
int					push(t_list **stack_to, t_list **stack_from);
int					rotate(t_list **stack);
int					reverseRotate(t_list **stack);

int					sa(t_list **stack_a);
int					sb(t_list **stack_b);
int					ss(t_list **stack_a, t_list **stack_b);
int					pa(t_list **stack_a, t_list **stack_b);
int					pb(t_list **stack_a, t_list **stack_b);
int					ra(t_list **stack_a);
int					rb(t_list **stack_b);
int					rr(t_list **stack_a, t_list **stack_b);
int					rra(t_list **stack_a);
int					rrb(t_list **stack_b);
int					rrr(t_list **stack_a, t_list **stack_b);

#endif