/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnahli <mnahli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:21:27 by mnahli            #+#    #+#             */
/*   Updated: 2025/02/11 11:00:34 by mnahli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

long	ft_atol(const char *str)
{
	int		i;
	int		val;
	long	num;
	long	check;

	i = 0;
	val = 1;
	num = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			val = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		check = num;
		num = num * 10 + (str[i] - '0');
		if ((num / 10) != check || num < 0)
			return (LONG_MAX);
		i++;
	}
	return ((long)(num * val));
}
