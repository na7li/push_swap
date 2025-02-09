/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnahli <mnahli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:03:35 by mnahli            #+#    #+#             */
/*   Updated: 2025/02/09 11:48:24 by mnahli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				data;
	int				index;
	struct s_stack	*next;
}					t_stack;

// ----------------------------- Utils ----------------------------- //
char				**ft_split(char const *s, char c);
long				ft_atol(const char *str);

// ------------------------ Input Validation ----------------------- //
int					parse_input(int ac, char **av, t_stack **a);
int					number_of_digits(char **str);
int					check_duplicates(t_stack *tmp, long nbr);
void				free_stack(t_stack **a);
void				free_array(char **str);
void				free_array_n_stack(char **str, t_stack **a);

// ----------------------- Stack Utilities ------------------------- //
int					stack_add_back(t_stack **a, int data);
int					stack_len(t_stack *tmp);

// --------------------- Sorting Utilities ------------------------- //
int					check_sorting(t_stack *tmp);
void				sort_large_stack(t_stack **a, t_stack **b, int range);
int					set_index(t_stack **a, int len);

// ------------------------ Operations ----------------------------- //
int					swap(t_stack **head);
void				sa(t_stack **a);
void				sb(t_stack **b);
void				ss(t_stack **a, t_stack **b);
int					push(t_stack **from, t_stack **to);
void				pa(t_stack **a, t_stack **b);
void				pb(t_stack **a, t_stack **b);
void				ra(t_stack **a);
int					rotate(t_stack **head);
void				rb(t_stack **b);
void				rr(t_stack **a, t_stack **b);
int					rrotate(t_stack **head);
void				rra(t_stack **a);
void				rrb(t_stack **b);
void				rrr(t_stack **a, t_stack **b);

// ------------------------- Sorting ------------------------------- //
int					sort(t_stack **a, t_stack **b);
void				sort_three(t_stack **a);
void				sort_five(t_stack **a, t_stack **b);

#endif