/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_stack_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnahli <mnahli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:09:27 by mnahli            #+#    #+#             */
/*   Updated: 2025/02/09 13:06:13 by mnahli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	copy_stack(t_stack **a, int **arr, int len)
{
	int		i;
	t_stack	*tmp;

	if (!a || !*a)
		return ;
	tmp = *a;
	*arr = malloc(sizeof(int) * len);
	if (!arr)
		return ;
	i = 0;
	while (i < len)
	{
		(*arr)[i] = tmp->data;
		i++;
		tmp = tmp->next;
	}
}

static void	sort_array(t_stack **a, int **arr, int len)
{
	int	i;
	int	j;
	int	tmp;

	copy_stack(a, arr, len);
	if (!arr)
		return ;
	i = 0;
	while (i < len - 1)
	{
		j = 0;
		while (j < len - i - 1)
		{
			if ((*arr)[j] > (*arr)[j + 1])
			{
				tmp = (*arr)[j];
				(*arr)[j] = (*arr)[j + 1];
				(*arr)[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	set_index(t_stack **a, int len)
{
	int		*arr;
	int		i;
	t_stack	*tmp;

	tmp = (*a);
	arr = NULL;
	sort_array(a, &arr, len);
	if (!arr)
		return (0);
	while (tmp)
	{
		i = -1;
		while (++i < len)
		{
			if (tmp->data == arr[i])
			{
				tmp->index = i;
				break ;
			}
		}
		tmp = tmp->next;
	}
	free(arr);
	arr = NULL;
	return (1);
}
