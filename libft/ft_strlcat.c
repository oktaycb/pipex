/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocubukcu <ocubukcu@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 00:50:05 by ocubukcu          #+#    #+#             */
/*   Updated: 2024/12/08 04:02:47 by ocubukcu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t len)
{
	size_t	d;
	size_t	i;

	d = 0;
	i = 0;
	if ((!dst || !src) && !len)
		return (0);
	while (dst[i] && i < len)
		i++;
	while (src[d] && (i + d + 1) < len)
	{
		dst[i + d] = src[d];
		d++;
	}
	if (i < len)
		dst[i + d] = '\0';
	return (i + ft_strlen(src));
}
