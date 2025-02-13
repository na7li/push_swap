/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnahli <mnahli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:06:20 by mnahli            #+#    #+#             */
/*   Updated: 2025/02/11 11:03:21 by mnahli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static int	is_empty(int ac, char **av)
{
	int	j;
	int	i;

	j = 1;
	i = 0;
	while (j < ac)
	{
		if (!av[j])
			return (0);
		i = 0;
		while (av[j][i] && (av[j][i] == ' ' || (av[j][i] >= 9
					&& av[j][i] <= 13)))
			i++;
		if (av[j][i] == '\0')
			return (0);
		j++;
	}
	return (1);
}

static int	is_valid_digit(int ac, char **av)
{
	int	j;
	int	i;

	j = 0;
	while (++j < ac)
	{
		i = 0;
		while (av[j][i])
		{
			if ((av[j][i] != ' ' && (av[j][i] < 9 || av[j][i] > 13)
					&& (av[j][i] < '0' || av[j][i] > '9') && av[j][i] != '-'
					&& av[j][i] != '+'))
				return (0);
			if ((av[j][i] == '-' || av[j][i] == '+') && ((av[j][i + 1] == '-'
						|| av[j][i + 1] == '+') || (i > 0 && av[j][i - 1] >= '0'
						&& av[j][i - 1] <= '9') || (av[j][i + 1] == '\0'
						|| av[j][i + 1] == ' ' || (av[j][i + 1] >= 9 && av[j][i
							+ 1] <= 13))))
				return (0);
			i++;
		}
	}
	return (1);
}

static int	process_input_numbers(char *arg, t_stack **a)
{
	char	**str;
	int		j;

	str = ft_split(arg, ' ');
	if (!str)
		return (0);
	j = -1;
	while (str[++j])
	{
		if (!(check_duplicates(*a, ft_atol(str[j]))))
		{
			free_array_n_stack(str, a);
			return (0);
		}
		if (!stack_add_back(a, (int)ft_atol(str[j])))
		{
			free_array_n_stack(str, a);
			return (0);
		}
	}
	free_array(str);
	return (1);
}

int	validate_digits(int ac, char **av, t_stack **a)
{
	int	i;

	i = 0;
	while (++i < ac)
	{
		if (!process_input_numbers(av[i], a))
			return (0);
	}
	return (1);
}

int	parse_input(int ac, char **av, t_stack **a)
{
	if (ac < 2 || !av)
		return (0);
	if (!is_empty(ac, av))
		return (0);
	if (!is_valid_digit(ac, av))
		return (0);
	if (!validate_digits(ac, av, a))
		return (0);
	return (1);
}
