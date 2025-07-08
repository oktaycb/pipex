/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocubukcu <ocubukcu@student.42kocaeli.com.t +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 00:50:05 by ocubukcu          #+#    #+#             */
/*   Updated: 2024/12/08 18:06:32 by ocubukcu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int i, size_t l)
{
	unsigned char	*ptr;
	size_t			x;

	x = 0;
	ptr = (unsigned char *)s;
	while (x < l)
	{
		if (ptr[x] == (unsigned char)i)
			return ((void *)(ptr + x));
		x++;
	}
	return (NULL);
}
