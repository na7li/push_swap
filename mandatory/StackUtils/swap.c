/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnahli <mnahli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 10:52:59 by mnahli            #+#    #+#             */
/*   Updated: 2025/02/15 12:16:52 by mnahli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	swap(t_stack **head)
{
	t_stack	*tmp;

	if (stack_len(*head) < 2)
		return (0);
	tmp = (*head)->next;
	(*head)->next = tmp->next;
	tmp->next = (*head);
	(*head) = tmp;
	tmp = NULL;
	return (1);
}

void	sa(t_stack **a)
{
	if (swap(a))
		write(1, "sa\n", 3);
}

void	sb(t_stack **b)
{
	if (swap(b))
		write(1, "sb\n", 3);
}
