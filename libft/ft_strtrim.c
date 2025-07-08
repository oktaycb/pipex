/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocubukcu <ocubukcu@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 00:50:05 by ocubukcu          #+#    #+#             */
/*   Updated: 2024/12/08 04:02:56 by ocubukcu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	size_t	head;
	size_t	tail;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	tail = ft_strlen(s1) - 1;
	head = 0;
	while (s1[head] && ft_strchr(set, s1[head]))
		++head;
	while (s1[tail] && ft_strchr(set, s1[tail]))
		--tail;
	trim = ft_substr(s1, head, tail - head + 1);
	return (trim);
}
