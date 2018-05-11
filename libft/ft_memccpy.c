/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 16:58:26 by akryvenk          #+#    #+#             */
/*   Updated: 2016/11/21 17:09:40 by akryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *restrict dst,
					const void *restrict src, int c, size_t n)
{
	char	*temp_dst;
	char	*temp_src;
	size_t	i;

	i = 0;
	temp_dst = (char *)dst;
	temp_src = (char *)src;
	while (n-- != 0)
	{
		temp_dst[i] = temp_src[i];
		if (temp_src[i] == c)
		{
			return (&temp_dst[i + 1]);
		}
		i++;
	}
	return (NULL);
}
