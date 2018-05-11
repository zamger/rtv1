/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 15:51:03 by akryvenk          #+#    #+#             */
/*   Updated: 2016/11/21 16:56:39 by akryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	char *temp_dst;
	char *temp_src;

	temp_dst = (char *)dst;
	temp_src = (char *)src;
	while (n)
	{
		*temp_dst++ = *temp_src++;
		n--;
	}
	return (dst);
}
