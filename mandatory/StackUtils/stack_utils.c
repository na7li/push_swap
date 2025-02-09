/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnahli <mnahli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:09:14 by mnahli            #+#    #+#             */
/*   Updated: 2025/02/09 10:44:35 by mnahli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	stack_create_node(t_stack **node, int data)
{
	*node = malloc(sizeof(t_stack));
	if (!*node)
		return ;
	(*node)->data = data;
	(*node)->next = NULL;
}

int	stack_add_back(t_stack **a, int data)
{
	t_stack	*tmp;
	t_stack	*node;

	node = NULL;
	stack_create_node(&node, data);
	if (!node)
		return (0);
	if (!*a)
		*a = node;
	else
	{
		tmp = *a;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = node;
	}
	return (1);
}
