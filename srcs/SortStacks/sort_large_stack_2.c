/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_stack_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnahli <mnahli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:22:13 by mnahli            #+#    #+#             */
/*   Updated: 2025/02/04 14:58:53 by mnahli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static int	find_max_index(t_stack *tmp)
{
	int	index_max;
	int	pos;
	int	i;

	index_max = tmp->index;
	pos = 0;
	i = 0;
	while (tmp)
	{
		if (tmp->index > index_max)
		{
			index_max = tmp->index;
			pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (pos);
}

static void	move_max_to_a(t_stack **a, t_stack **b)
{
	int	len;
	int	max_pos;

	while (*b)
	{
		max_pos = find_max_index(*b);
		len = stack_len(*b);
		if (max_pos > len / 2)
			while (max_pos++ < len)
				rrb(b);
		else if (max_pos <= len / 2 && max_pos != 0)
			while (max_pos-- > 0)
				rb(b);
		else if (max_pos == 0)
			pa(a, b);
	}
}

static void	push_chunks_to_b(t_stack **a, t_stack **b, int range)
{
	int	start;

	start = 0;
	while (*a)
	{
		if ((*a)->index >= start && (*a)->index <= range)
		{
			pb(a, b);
			start++;
			range++;
		}
		else if ((*a)->index < start)
		{
			pb(a, b);
			rb(b);
			start++;
			range++;
		}
		else
			ra(a);
	}
}

void	sort_large_stack(t_stack **a, t_stack **b, int range)
{
	push_chunks_to_b(a, b, range);
	move_max_to_a(a, b);
}
