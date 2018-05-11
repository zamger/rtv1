/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 17:21:29 by akryvenk          #+#    #+#             */
/*   Updated: 2016/11/23 17:25:29 by akryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *restrict s1, const char *restrict s2, size_t n)
{
	size_t	count_s1;
	size_t	count_s2;
	char	*dst;
	char	*src;

	dst = s1;
	src = (char*)s2;
	count_s2 = n;
	while (n-- && *dst)
		dst++;
	count_s1 = dst - s1;
	n = count_s2 - count_s1;
	if (n == 0)
		return (count_s1 + ft_strlen(src));
	while (*src)
	{
		if (n != 1)
		{
			*dst++ = *src;
			n--;
		}
		src++;
	}
	*dst = '\0';
	return (count_s1 + (src - s2));
}
