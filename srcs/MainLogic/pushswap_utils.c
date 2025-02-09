/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnahli <mnahli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 09:30:47 by mnahli            #+#    #+#             */
/*   Updated: 2025/02/09 12:24:21 by mnahli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	check_sorting(t_stack *tmp)
{
	while (tmp->next)
	{
		if (tmp->data > tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	stack_len(t_stack *tmp)
{
	int	c;

	c = 0;
	while (tmp)
	{
		c++;
		tmp = tmp->next;
	}
	return (c);
}

int	sort(t_stack **a, t_stack **b)
{
	int	len;

	len = stack_len(*a);
	if (len == 2)
		sa(a);
	else if (len == 3)
		sort_three(a);
	else if (len == 5 || len == 4)
		sort_five(a, b);
	else if (len > 5)
	{
		if (!set_index(a, len))
			return (0);
		if (len <= 100)
			sort_large_stack(a, b, 15);
		else if (len <= 500)
			sort_large_stack(a, b, 35);
		else
			sort_large_stack(a, b, 45);
	}
	return (1);
}
