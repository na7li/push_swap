/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnahli <mnahli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:55:33 by mnahli            #+#    #+#             */
/*   Updated: 2025/02/05 11:03:36 by mnahli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	sort_three(t_stack **a)
{
	if ((*a)->next->data > (*a)->data
		&& (*a)->next->data > (*a)->next->next->data)
		rra(a);
	if ((*a)->data > (*a)->next->data && (*a)->data > (*a)->next->next->data)
		ra(a);
	if ((*a)->data > (*a)->next->data && (*a)->data < (*a)->next->next->data)
		sa(a);
}

static int	find_min(t_stack *head)
{
	int	pos;
	int	i;
	int	data;

	i = 0;
	pos = i;
	data = head->data;
	while (head)
	{
		if (head->data < data)
		{
			data = head->data;
			pos = i;
		}
		i++;
		head = head->next;
	}
	return (pos);
}

static void	move_min_to_top(t_stack **a)
{
	int	min_pos;
	int	new_len;

	new_len = stack_len(*a);
	min_pos = find_min(*a);
	if (min_pos <= new_len / 2)
	{
		while (min_pos-- != 0)
			ra(a);
	}
	else
	{
		while (min_pos++ < new_len)
			rra(a);
	}
}

void	sort_five(t_stack **a, t_stack **b)
{
	int	len;

	len = stack_len(*a);
	if (len < 4 || len > 5)
		return ;
	move_min_to_top(a);
	if (check_sorting(*a))
		return ;
	pb(a, b);
	if (len == 5)
	{
		move_min_to_top(a);
		pb(a, b);
	}
	sort_three(a);
	pa(a, b);
	if (len == 5)
		pa(a, b);
}
