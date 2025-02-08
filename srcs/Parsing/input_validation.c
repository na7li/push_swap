/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnahli <mnahli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:19:10 by mnahli            #+#    #+#             */
/*   Updated: 2025/02/08 10:43:02 by mnahli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	free_array(char **str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

void	free_stack(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*curr;

	curr = *a;
	if (!a || !*a)
		return ;
	while (curr)
	{
		tmp = curr;
		tmp->data = 0;
		curr = curr->next;
		free(tmp);
	}
	*a = NULL;
}

int	check_duplicates(t_stack *tmp, long nbr)
{
	if (nbr < INT_MIN || nbr > INT_MAX)
		return (0);
	if (!tmp)
		return (1);
	while (tmp)
	{
		if (tmp->data == (int)nbr)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
