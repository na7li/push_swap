/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnahli <mnahli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:31:04 by mnahli            #+#    #+#             */
/*   Updated: 2025/02/04 14:58:35 by mnahli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (!parse_input(ac, av, &stack_a))
	{
		free_stack(&stack_a);
		return (write(1, "Error\n", 6));
	}
	if (!check_sorting(stack_a))
		sort(&stack_a, &stack_b);
	free_stack(&stack_a);
	return (0);
}
