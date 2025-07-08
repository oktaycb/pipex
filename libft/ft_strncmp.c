/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocubukcu <ocubukcu@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 00:50:05 by ocubukcu          #+#    #+#             */
/*   Updated: 2024/12/08 04:02:52 by ocubukcu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t l)
{
	unsigned char	*pt;
	unsigned char	*pt2;

	pt = (unsigned char *)s1;
	pt2 = (unsigned char *)s2;
	while (*pt && l && *pt == *pt2)
	{
		++pt;
		++pt2;
		--l;
	}
	if (l)
		return (*pt - *pt2);
	else
		return (0);
}
