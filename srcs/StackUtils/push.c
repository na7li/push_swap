/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnahli <mnahli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 10:15:34 by mnahli            #+#    #+#             */
/*   Updated: 2025/02/05 15:00:37 by mnahli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	push(t_stack **from, t_stack **to)
{
	t_stack	*from_1;

	if (!from || !*from || !to)
		return (0);
	from_1 = *from;
	(*from) = (*from)->next;
	from_1->next = (*to);
	(*to) = from_1;
	return (1);
}

void	pa(t_stack **a, t_stack **b)
{
	if (push(b, a))
		write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b)
{
	if (push(a, b))
		write(1, "pb\n", 3);
}
