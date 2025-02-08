/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnahli <mnahli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 10:37:43 by mnahli            #+#    #+#             */
/*   Updated: 2025/02/08 11:02:27 by mnahli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

