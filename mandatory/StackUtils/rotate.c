/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnahli <mnahli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 10:56:49 by mnahli            #+#    #+#             */
/*   Updated: 2025/02/09 09:20:48 by mnahli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	rotate(t_stack **head)
{
	t_stack	*curr;
	t_stack	*end;

	curr = *head;
	end = *head;
	if (!head || !*head || !(*head)->next)
		return (0);
	while (end->next)
		end = end->next;
	(*head) = (*head)->next;
	curr->next = NULL;
	end->next = curr;
	return (1);
}

void	ra(t_stack **a)
{
	if (rotate(a))
		write(1, "ra\n", 3);
}

void	rb(t_stack **b)
{
	if (rotate(b))
		write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	if (rotate(a) && rotate(b))
		write(1, "rr\n", 3);
}
