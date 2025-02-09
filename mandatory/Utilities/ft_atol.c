/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnahli <mnahli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:21:27 by mnahli            #+#    #+#             */
/*   Updated: 2025/02/09 09:20:48 by mnahli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

long	ft_atol(const char *str)
{
	int					i;
	int					val;
	unsigned long long	num;

	i = 0;
	val = 1;
	num = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			val = val * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (val == 1 && num > 9223372036854775807LL)
			return (-1);
		if (val == -1 && num > 9223372036854775807LL)
			return (0);
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return ((long)(num * val));
}
