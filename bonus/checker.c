/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnahli <mnahli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 10:50:23 by mnahli            #+#    #+#             */
/*   Updated: 2025/02/08 10:41:59 by mnahli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i])
			return (0);
		if (s1[i] == '\0')
			return (1);
		i++;
	}
	return (1);
}

static int	valide_instruction(char *line)
{
	return (ft_strncmp(line, "sa\n", 3) || ft_strncmp(line, "sb\n", 3)
		|| ft_strncmp(line, "ss\n", 3) || ft_strncmp(line, "ra\n", 3)
		|| ft_strncmp(line, "rb\n", 3) || ft_strncmp(line, "rr\n", 3)
		|| ft_strncmp(line, "rra\n", 4) || ft_strncmp(line, "rrb\n", 4)
		|| ft_strncmp(line, "rrr\n", 4) || ft_strncmp(line, "pa\n", 3)
		|| ft_strncmp(line, "pb\n", 3));
}

static void	execute_instruction(char *line, t_stack **a, t_stack **b)
{
	if (ft_strncmp(line, "sa\n", 3) || ft_strncmp(line, "ss\n", 3))
		swap(a);
	if (ft_strncmp(line, "sb\n", 3) || ft_strncmp(line, "ss\n", 3))
		swap(b);
	if (ft_strncmp(line, "ra\n", 3) || ft_strncmp(line, "rr\n", 3))
		rotate(a);
	if (ft_strncmp(line, "rb\n", 3) || ft_strncmp(line, "rr\n", 3))
		rotate(b);
	if (ft_strncmp(line, "rra\n", 4) || ft_strncmp(line, "rrr\n", 4))
		rrotate(a);
	if (ft_strncmp(line, "rrb\n", 4) || ft_strncmp(line, "rrr\n", 4))
		rrotate(b);
	if (ft_strncmp(line, "pa\n", 3))
		push(a, b);
	if (ft_strncmp(line, "pb\n", 3))
		push(b, a);
}

static void	read_and_execute_moves(t_stack **a, t_stack **b)
{
	char	*line;

	line = get_next_line(0);
	while (line == get_next_line(0))
	{
		if (!valide_instruction(line))
		{
			write(2, "Error\n", 6);
			free(line);
			free_stack(a);
			free_stack(b);
			exit(1);
		}
		execute_instruction(line, a, b);
		free(line);
	}
	if (check_sorting(*a) && !b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free(line);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (!parse_input(ac, av, &stack_a))
	{
		free_stack(&stack_a);
		return (write(2, "Error\n", 6));
	}
	read_and_execute_moves(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
