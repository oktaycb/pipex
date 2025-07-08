/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocubukcu <ocubukcu@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 00:50:05 by ocubukcu          #+#    #+#             */
/*   Updated: 2024/12/08 04:02:11 by ocubukcu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_len(int i)
{
	int	length;

	length = 0;
	if (i <= 0)
		length++;
	while (i != 0)
	{
		length++;
		i /= 10;
	}
	return (length);
}

char	*ft_itoa(int i)
{
	char	*str;
	long	num;
	size_t	size;

	num = i;
	size = num_len(i);
	if (i < 0)
		num *= -1;
	str = (char *)malloc(size + 1);
	if (!str)
		return (NULL);
	*(str + size--) = '\0';
	while (num > 0)
	{
		*(str + size--) = num % 10 + '0';
		num /= 10;
	}
	if (size == 0 && str[1] == '\0')
		*(str + size) = '0';
	else if (size == 0 && str[1])
		*(str + size) = '-';
	return (str);
}
