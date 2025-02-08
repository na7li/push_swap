/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnahli <mnahli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 12:25:44 by mnahli            #+#    #+#             */
/*   Updated: 2025/02/05 15:35:20 by mnahli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	rrotate(t_stack **head)
{
	t_stack	*curr;
	t_stack	*end;

	end = *head;
	if (!head || !*head || !(*head)->next)
		return (0);
	while (end->next->next)
		end = end->next;
	curr = end->next;
	curr->next = *head;
	*head = curr;
	end->next = NULL;
	return (1);
}

void	rra(t_stack **a)
{
	if (rrotate(a))
		write(1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	if (rrotate(b))
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	if (rrotate(a) && rrotate(b))
		write(1, "rrr\n", 4);
}
