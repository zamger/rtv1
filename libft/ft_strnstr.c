/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 15:03:04 by akryvenk          #+#    #+#             */
/*   Updated: 2016/11/24 15:03:05 by akryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t i)
{
	const char	*s1;
	const char	*s2;
	size_t		j;
	size_t		k;

	j = 0;
	if (!*to_find)
		return (char*)(str);
	while (*str && j < i)
	{
		s1 = str;
		s2 = to_find;
		k = j;
		while (*s1 && *s2 && !(*s1 - *s2) && k < i)
		{
			s1++;
			s2++;
			k++;
		}
		if (!*s2)
			return (char*)(str);
		j++;
		str++;
	}
	return (NULL);
}
