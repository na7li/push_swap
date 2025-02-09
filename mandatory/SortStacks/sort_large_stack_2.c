/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_stack_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnahli <mnahli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:22:13 by mnahli            #+#    #+#             */
/*   Updated: 2025/02/09 12:17:48 by mnahli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static int	find_max_index_pos(t_stack *tmp)
{
	int	max_index;
	int	pos;
	int	i;

	max_index = tmp->index;
	pos = 0;
	i = 0;
	while (tmp)
	{
		if (tmp->index > max_index)
		{
			max_index = tmp->index;
			pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (pos);
}

static void	push_max_to_a(t_stack **a, t_stack **b)
{
	int	len;
	int	max_index_pos;

	while (*b)
	{
		max_index_pos = find_max_index_pos(*b);
		len = stack_len(*b);
		if (max_index_pos > len / 2)
			while (max_index_pos++ < len)
				rrb(b);
		else if (max_index_pos <= len / 2 && max_index_pos != 0)
			while (max_index_pos-- > 0)
				rb(b);
		else if (max_index_pos == 0)
			pa(a, b);
	}
}

static void	push_range_to_b(t_stack **a, t_stack **b, int range)
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
	push_range_to_b(a, b, range);
	push_max_to_a(a, b);
}
