/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocubukcu <ocubukcu@student.42kocaeli.com.t +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 23:34:33 by ocubukcu          #+#    #+#             */
/*   Updated: 2024/12/16 00:48:45 by ocubukcu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	while (i[str] == 32 || (i[str] >= 9 && i[str] <= 13))
		i++;
	if (i[str] == '-' || i[str] == '+')
	{
		sign *= (i[str] == '-') * -1 + !(i[str] == '-');
		i++;
	}
	while (i[str] >= '0' && i[str] <= '9')
		res = res * 10 + i++[str] - 48;
	return (res * sign);
}
